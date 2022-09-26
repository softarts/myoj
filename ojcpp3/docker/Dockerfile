FROM gcc:latest
LABEL maintainer="Zhou Rui" \
      description="Basic C++ stuff." \
      version="0.1.0"
ARG DEBIAN_FRONTEND=noninteractive
ENV TZ=Asia/Shanghai
RUN apt-get update -y
RUN apt-get install -y --no-install-recommends\
                    git \
                    curl \                    
                    build-essential \
                    net-tools \
                    telnet \
                    cmake && \                    
    apt-get autoclean && \
    apt-get autoremove && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*