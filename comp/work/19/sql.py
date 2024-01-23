import sqlite3
import os

def createTables():

    cur.executescript(
            '''CREATE TABLE class (
            class_id INT(4) PRIMARY KEY,
            name TEXT NOT NULL,
            teacher VARCHAR(50));

        CREATE TABLE pupil (
            pupil_id INT(6) PRIMARY KEY,
            firstName VARCHAR(50) NOT NULL,
            lastName VARCHAR(50) NOT NULL,
            age INT NOT NULL,
            tutor VARCHAR(50));

        CREATE TABLE enrol (
            enrol_id INTEGER PRIMARY KEY AUTOINCREMENT,
            pupil_id INT NOT NULL,
            class_id INT NOT NULL,
            FOREIGN KEY(pupil_id) REFERENCES pupil(pupil_id),
            FOREIGN KEY(class_id) REFERENCES class(class_id));''')

def populateDB():

    db_class = [("0001", "Maths", "N.Inskip"),
        ("0002", "Criminology", "G.Duffy"),
        ("0003", "English", "C.Reiley"),
        ("0004", "History(Modern)", "B.Batters"),
        ("0005", "Geography", "A.Podesta"),
        ("0006", "Computing", "N.Inskip")]

    db_pupil = [("000001", "John", "Potato", 16, "G.Duffy"),
        ("000002", "Sammi", "Grange", 16, "G.Duffy"),
        ("000003", "Don", "Paisley", 16, "A.Podesta"),
        ("000004", "Barny", "Trex", 16, "B.Batters"),
        ("000005", "Lara", "Croft", 17, "B.Batters"),]

    db_enrol = [(1, 1),
        (2, 1),
        (3, 1),
        (2, 2),
        (3, 3),
        (5, 4),
        (5, 2),
        (5, 3),
        (4, 1),
        (1, 2)]


    #add multiple list entries to the database
    cur.executemany("INSERT INTO class (class_id, name, teacher) VALUES (?, ?, ?);", db_class)
    cur.executemany("INSERT INTO pupil (pupil_id, firstName, lastName, age, tutor) VALUES (?, ?, ?, ?, ?);", db_pupil)
    cur.executemany("INSERT INTO enrol (pupil_id, class_id) VALUES (?, ?);", db_enrol)
    conn.commit()

def query(query):
    #print out unformatted results
    rows = cur.execute(query).fetchall()
    for i in rows:
        print(i)
#MAIN


if not os.path.exists('college_dbase.db'):
    conn = sqlite3.connect('college_dbase.db')
    cur = conn.cursor()
    createTables()
    populateDB()
else:
    conn = sqlite3.connect('college_dbase.db')
    cur = conn.cursor()


#query to be executed
q1 = '''SELECT *
FROM pupil
WHERE pupil.age = 17
ORDER BY pupil.lastName
;'''



query(q1)

conn.close()

