#!/bin/bash

function init () {
	if [ ! -e "main.zpy" ]; then
		touch main.zpy 

		echo -e "(defun main int)" >> main.zpy
		printf "\t(printstr \"hello world\\\n\")\n" >> main.zpy
		echo -e "(endfun)" >> main.zpy

		echo "#!/bin/sh" > zpybuild.sh
		echo "zpy ./main.zpy -o main" >> zpybuild.sh
	else
		echo "zpypkg already in use!"
	fi
}

function advinit () {
	if [ ! -e "main.zpy" ]; then
		touch main.zpy 

		echo -e "(defun main int)" >> main.zpy
		printf "\t(printstr \"hello world\\\n\")\n" >> main.zpy
		echo -e "(endfun)" >> main.zpy

		touch zpybuild.sh
		echo "#!/bin/sh" > zpybuild.sh
		echo "zpy ./main.zpy -c -o main.c" >> zpybuild.sh
		echo "cc main.c /usr/local/share/zpylib/zpylib.o -o main -I/usr/local/share/zpylib/include -Wno-implicit-function-declaration" >> zpybuild.sh
		echo "rm -rf main.c" >> zpybuild.sh

	else
		echo "zpypkg already in use!"
	fi
}

function build (){
	sh ./zpybuild.sh	
}

function run (){
	./main	
}

function clean (){
	rm -f ./main
}

function remove () {
	if [ -e "main.zpy" ]; then
		rm main.zpy zpybuild.sh
	else
		echo "zpypkg not in use!"
	fi
}

case $@ in
	"init") 
		init
		;;
	"advinit")
		advinit
		;;
	"build")
		build
		;;
	"run")
		build
		run
		;;
	"clean")
		clean
		;;
	"remove")
		remove	
		;;
	*)
		echo "unknown option ${@}"
esac
