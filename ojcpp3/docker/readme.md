# Run
docker build -t mycpp .
docker run -it --rm -v $(pwd):/work mycpp:latest /bin/bash
docker run -it --rm -v $(pwd):/work gcc:latest /bin/bash
