FROM gcc:latest

WORKDIR /app

ADD hello1.cpp .
ADD hello2.cpp .
ADD hello3.cpp .
ADD hello4.cpp .
ADD helloscript.sh .


RUN g++ hello1.cpp -o hello1
RUN g++ hello2.cpp -o hello2
RUN g++ hello3.cpp -o hello3
RUN g++ hello4.cpp -o hello4


RUN chmod +x helloscript.sh


CMD ["./helloscript.sh"]

