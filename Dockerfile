FROM thewtex/opengl

ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get -yyq update \
    && apt-get -yyq install \
    	cmake \
	freeglut3 \
	freeglut3-dev \
	ninja-build \
	libgl1-mesa-dev \
	libglew-dev \
    && apt-get -yyq clean \
    && rm -rf /var/lib/apt/lists/*

COPY src /src
WORKDIR /build
RUN cmake -G Ninja /src
RUN cmake --build . -- install
