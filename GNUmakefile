hv.ex5: hv.mq5 hv.dll
	-metaeditor64.exe /compile:hv.mq5 /log:log.log
	cat log.log
	rm log.log

hv.dll: hv.c
	clang -Wall -shared -o hv.dll hv.c -lm
