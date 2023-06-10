#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

void printPermissions(mode_t mode) {
    printf((S_ISDIR(mode)) ? "d" : "-");
    printf((mode & S_IRUSR) ? "r" : "-");
    printf((mode & S_IWUSR) ? "w" : "-");
    printf((mode & S_IXUSR) ? "x" : "-");
    printf((mode & S_IRGRP) ? "r" : "-");
    printf((mode & S_IWGRP) ? "w" : "-");
    printf((mode & S_IXGRP) ? "x" : "-");
    printf((mode & S_IROTH) ? "r" : "-");
    printf((mode & S_IWOTH) ? "w" : "-");
    printf((mode & S_IXOTH) ? "x" : "-");
    printf("   ");
}

void printFileInfo(struct dirent *entry) {
    char datetime[20];
    struct tm *tm;
    struct passwd *pwd;
    struct group *grp;
    struct stat filestat;

    if (stat(entry->d_name, &filestat) != 0)
        return;

    pwd = getpwuid(filestat.st_uid);
    grp = getgrgid(filestat.st_gid);

    if(pwd == NULL || grp == NULL)
        return;

    tm = localtime(&(filestat.st_mtime));

    strftime(datetime, sizeof(datetime), "%b %d %H:%M", tm);
    
    printPermissions(filestat.st_mode);
    printf("%-10s", pwd->pw_name);
    printf("%-10s", grp->gr_name);
    printf("%-10lld", (long long)filestat.st_size);
    printf("%-16s", datetime);
    printf("%-10s", entry->d_name);
    printf("\n");
}

int main() {
    DIR *dir;
    struct dirent *entry;
    
    dir = opendir(".");
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }
    
    while ((entry = readdir(dir)) != NULL) {
        if(entry->d_name[0] == '.')
            continue;

        printFileInfo(entry);
    }
    
    closedir(dir);
    return 0;
}