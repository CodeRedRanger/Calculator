#Stage 1: Build environment
# Use a base image with a recent C++ compiler and build tools
FROM lukka/vcpkg AS builder

# Set environment vcpkg root
# Configure cmake to find vcpkg automatically
ENV VCPKG_ROOT=/usr/src/vcpkg
# See: http://learn.microsoft.com/en-us/vcpkg/users/buildsystem/cmake-integration#manifest-mode
ENV CMAKE_TOOLCHAIN_FILE=${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake

#Copy the project source code
WORKDIR /usr/src/app
COPY . .

#Build the project using CMake with vcpkg
RUN cmake -B build
RUN cmake --build build

#Stage 2: Minimal runtime image
FROM lukka/vcpkg

#Install runtime libraries
RUN apt-get update && apt-get -y install \
    libgtk-3-0

#Copy the built binary and runtime dependencies from the build stage
COPY --from=builder /usr/src/app/build/Calc_App /user/lcoal/bin/Calc_App
COPY --from=builder /usr/src/vcpkg/installed/x64-linux/bin /usr/local/bin
COPY --from=builder /usr/src/vcpkg/installed/x64-linux/lib /usr/local/lib

# Define the entrypoint (change app name)
ENTRYPOINT ["/usr/local/bin/Calc_App"]
