FROM debian:latest

RUN apt update && apt install -y python3 python3-pip
RUN pip3 install flask

RUN apt install -y cmake

ADD . /app
WORKDIR /app
RUN cd /app && mkdir build && cd build && cmake .. && make && rm -rf build

RUN adduser techproguser
USER techproguser

EXPOSE 5000
CMD flask run --host 0.0.0.0