FROM gcc:latest

RUN apt-get update && apt-get install -y cmake

WORKDIR /app

COPY ./src ./src
COPY CMakeLists.txt CMakeLists.txt

EXPOSE 5678 5678

RUN cmake .
RUN make

CMD ["./BSKeyVS"]
