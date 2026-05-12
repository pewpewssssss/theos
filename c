#import <Foundation/Foundation.h>
#import <spawn.h>
#import <sys/wait.h>

extern char **environ;

int run_command(const char *path, char *const argv[]) {
    pid_t pid;
    int status;
    
    // Spawn the process
    int spawn_ret = posix_spawn(&pid, path, NULL, NULL, argv, environ);
    
    if (spawn_ret == 0) {
        // Wait for dpkg to finish
        if (waitpid(pid, &status, 0) != -1) {
            return WEXITSTATUS(status);
        }
    }
    return -1;
}

int main(int argc, char **argv) {
    @autoreleasepool {
        if (argc < 2) {
            printf("Usage: debload <path_to_deb>\n");
            return 1;
        }

        char *debPath = argv[1];
        printf("debload: Installing %s...\n", debPath);

        // Define the dpkg command: dpkg -i <path>
        char *const args[] = {(char *)"/usr/bin/dpkg", (char *)"-i", debPath, NULL};

        int result = run_command("/usr/bin/dpkg", args);

        if (result == 0) {
            printf("debload: Success!\n");
        } else {
            printf("debload: Failed with exit code %d\n", result);
        }

        return result;
    }
}
