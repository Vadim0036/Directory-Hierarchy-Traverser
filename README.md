# Directory-Hierarchy-Traverser
The program is designed to traverse a directory hierarchy, starting from a specified root directory.

Program Description:

The program is designed to traverse a directory hierarchy, starting from a specified root directory, and count the types of files it encounters. It will recursively visit each directory and check every file it reads. The program categorizes the files based on their types, such as regular files, directories, symbolic links, and other special file types (e.g., sockets, devices).

Functionality:

Directory Traversal:

The program uses recursion or an iterative approach with a queue to explore subdirectories and their contents.
File Type Detection:

For each file, it determines the file type using system calls like stat() or similar functions. It can detect whether the file is a regular file, a directory, a symbolic link, a socket, or other special file types.
Counting File Types:

The program maintains a counter for each file type. For example, it could keep a count of the number of regular files, directories, symbolic links, etc.
Output:

At the end of the traversal, the program prints the total count of each file type found during the traversal.
Usage:

Input: The program takes the path to a directory as input.
Output: The program prints the counts of each file type it encountered in the directory hierarchy.
