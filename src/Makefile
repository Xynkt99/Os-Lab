
bin/server:	monitor/monitor.c  bin/consumer bin/producer
	gcc -o bin/server -pthread monitor/monitor.c 

bin/consumer: consumer/consumer.c 
	gcc -o bin/consumer consumer/consumer.c 


bin/producer: producer/producer.c
	gcc -o bin/producer producer/producer.c 

clean:
	-rm bin/consumer
	-rm bin/producer
	-rm bin/server

