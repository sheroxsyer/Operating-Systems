# Use an official image as a parent image
FROM ubuntu:latest

# Set the working directory
WORKDIR /app

# Copy the C++ source files and the shell script into the container
COPY hello1.cpp .
COPY hello2.cpp .
COPY hello3.cpp .
COPY hello4.cpp .
COPY helloscript.sh .

# Install g++ compiler (or any other build tools you need)
RUN apt-get update && apt-get install -y g++

# Compile the C++ source files
RUN g++ hello1.cpp -o hello1
RUN g++ hello2.cpp -o hello2
RUN g++ hello3.cpp -o hello3
RUN g++ hello4.cpp -o hello4

# Make the shell script executable
RUN chmod +x helloscript.sh

# Define the command to run when the container starts
CMD ["./hellosscript.sh"]

