#include "lib/mysocket.cpp"


int main(int argc, char* argv[]) {
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    printf("socket blocking state is %d\n", isblocking(fd));
}
