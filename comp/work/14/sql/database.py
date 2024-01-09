#### database_tool.py

# Import libraries:
from tkinter import *
from tkinter.scrolledtext import *
import sqlite3
import os # needed to obtain OS specific methods for navigating file structures

# Global Variables
current_database = ''
databases = []
textbox_colour = 'linen'

#### Utility Functions
def pretty_tables(info, body):
    '''Called to handle SQL queries beginning with SELECT.
       It then formats the output from sqlite3 into easy tables'''
    column_widths = []
    headings = []
    
    # work hard to get headings and put them into a list
    # set column widths to length of heading strings
    for row in info:
        headings.append(row[0])
        column_widths.append(len(row[0]))

    # update column widths from body text
    for row in body:
        counter = 0
        for item in row:
            length = len(str(item))
            if length > column_widths[counter]:
                column_widths[counter] = length
            counter = counter+1
        
    # format results with a lot of string manipulation
    top_row = '+'
    heading_text = '| '
    body_text = '| '
    for width in column_widths:
        top_row = top_row + '-'*(width+3)
    top_row = top_row[:-1] + '+\n'
    
    counter = 0
    for item in headings:
        padding = ' '*(column_widths[counter] - len(str(item)))
        heading_text = heading_text + item + padding + ' | '
        counter = counter+1
    heading_text = heading_text + '\n'

    for row in body:
        counter = 0
        for item in row:
            padding = ' '*(column_widths[counter] - len(str(item)))
            body_text = body_text + str(item) + padding + ' | '
            counter = counter+1
        body_text = body_text + '\n| '
    body_text = body_text[:-2]
        
    text = top_row + heading_text + top_row + body_text + top_row
    return text

def update_databases():
    '''Looks through the folder where this script is
       found looking for database files'''
    number_of_dbs = 0
    files = os.listdir()
    for file in files:
        # select files where the last three characters are .db
        if file[-3:] == '.db':
            databases.append(file)

#### Button functions
def build_database():
    '''Creates a new database and rebuilds the dropdown menu'''
    global var
    global current_database
    global db_dropdown
    db_name = db_name_textbox.get() + '.db'
    if db_name == '.db':
        output_textbox.insert(END, 'ERROR: Please enter a name for your new database.\n\n')

    elif db_name in databases:
        output_textbox.insert(END, 'ERROR: Database already exists.\n\n')
    else:
        try:
            with sqlite3.connect(db_name) as db:
                cursor = db.cursor()
        except:
            output_textbox.insert(END, 'ERROR: Please try again.\n\n')
        else:
            # If all OK add new name to databases list
            databases.append(db_name)

            # Now destroy current dropdown menu and rebuild it with new list.
            db_dropdown.destroy()

            var = StringVar()
            var.set('Choose database:')
            db_dropdown = OptionMenu(frame_buttons, var, *databases, command=choose_database)
            db_dropdown.grid(row=0, column=0, sticky=NW)
 
def choose_database(value):
    '''Takes the appropriate database passed from the dropdown menu
       selection and updates the current_database global variable'''
    global current_database
    current_database = value
    
def clear_output():
    '''Empies the text in the Output textbox'''
    output_textbox.delete(0.0, END)  # clear output text box

def get_tables():
    '''Finds a list of tables in the database'''
    query = '''SELECT name FROM sqlite_master
             WHERE type='table'
             ORDER BY name;'''
    run_sql(query)

def quit_tool():
    '''closes the window and then quits'''
    window.withdraw()
    window.quit()

def run_query():
    '''Collects the query string from the SQL entry textbox and runs the query'''
    # Check database selected:
    if current_database == '':
        output_textbox.insert(END, 'ERROR: Please choose a database\n\n')
    else:
        # Fetch users SQL
        query = sql_textbox.get(0.0, END)
        run_sql(query)
        sql_textbox.delete(0.0, END)  # clear output text box
        print(query)

def run_sql(sql):
    '''Executes any SQL code passed to it and displays the output in the
       Output textbox'''
    # Connect to the database and run the SQL passed to this function
    with sqlite3.connect(current_database) as db:
        cursor = db.cursor()
        # the cursor is required to navigate the database
        cursor.execute(sql)
        db.commit()
        
        # use fetchall() to collect result of queries
        result = cursor.fetchall()

        # if a SELECT query, process result into a table
        if sql[:6].upper() == 'SELECT':
            table_info = cursor.description
            result = pretty_tables(table_info, result)
        else:
            result = str(result)
            
        result = result + '\n\n'
        # Display the value held in the variable result in the output textbox
        if len(result) > 50:  
            clear_output()
        output_textbox.insert(END, result)
   
##### main:
window = Tk()
window.title('Python Database Tool')

update_databases()

# Import images
python_logo = PhotoImage(file='python-logo.gif')
sqlite_logo = PhotoImage(file='sqlite-logo.gif')

# Create frames
frame_new_db = Frame(window)
frame_new_db.grid(row=3, column=0, pady=20, sticky=SW)

frame_buttons = Frame(window)
frame_buttons.grid(row=0, column=0)

frame_query = Frame(window)
frame_query.grid(row=2, column=0, sticky=NW)

frame_output = Frame(window)
frame_output.grid(row=2, column=1, rowspan=2)

# Add labels
Label(frame_new_db, text='Create a new database:').grid(row=0, column=0, columnspan=2, sticky=NW)
Label(frame_new_db, text='Choose a name: ').grid(row=1, column=0, sticky=NW)
Label(frame_query, text='Add SQL:').grid(row=0, column=0, sticky=NW)
Label(frame_output, text='Output: ').grid(row=0, column=0, sticky=NW)

# Create database name box
db_name_textbox = Entry(frame_new_db, width=10)
db_name_textbox.grid(row=1, column=1, sticky=NW)

# Create sql entry box
sql_textbox = Text(frame_query, width=50, height=10, background=textbox_colour)
sql_textbox.grid(row=1, column=0, sticky=NW)

# Create scrolling textbox
output_textbox = ScrolledText(frame_output, width=65, height=20, background=textbox_colour)
output_textbox.grid(row=1, column=0, sticky=NW)

# Add images in label widgets
Label(window, image=python_logo).grid(row=1, column=0, sticky=NW)
Label(window, image=sqlite_logo).grid(row=1, column=1, sticky=NW)

# Add buttons
button_quit = Button(frame_buttons, text="Quit", width=10, command=quit_tool)
button_quit.grid(row=0, column=2, sticky=NE)
button_clear = Button(frame_output, text="Clear result box", command=clear_output)
button_clear.grid(row=2, column=0, sticky=NE)
button_run = Button(frame_query, text="Run SQL", width=10, command=run_query)
button_run.grid(row=2, column=0, sticky=NW)
button_tables = Button(frame_buttons, text="List Tables", width=15, command=get_tables)
button_tables.grid(row=0, column=1, sticky=NE)
button_submit = Button(frame_new_db, text="Build database", command=build_database)
button_submit.grid(row=2, column=0, sticky=NW)

# Add dropdown menu
var = StringVar()
var.set('Choose database:')
# builds dropdown from databases list but if empty (first use situation) handles this.
db_dropdown = OptionMenu(frame_buttons, var, *databases if databases else ['empty'], command=choose_database)
db_dropdown.grid(row=0, column=0, sticky=NW)

##### Run mainloop
window.mainloop()

