// // ‘wc’ (word count)是Unix下的一个工具, 
// 它可以统计一个文本文件中字符的个数，
// 单词的个数以及行数 (其中我们也统计不可打
//     印的字符和空白字符，单词是以空白字符分割的)。
//     请实现一个 ‘wc’ 程序，当传入的参数个数不对时，
//     请给出提示信息。

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>

// 显示帮助信息
void show_usage(const char *program_name) {
    printf("Usage: %s [OPTION]... [FILE]...\n", program_name);
    printf("Print newline, word, and byte counts for each FILE.\n\n");
    printf("Options:\n");
    printf("  -c, --bytes    print the byte counts\n");
    printf("  -w, --words    print the word counts\n");
    printf("  -l, --lines    print the newline counts\n");
    printf("  -h, --help     display this help and exit\n");
    printf("\nWith no FILE, or when FILE is -, read standard input.\n");
    printf("With no options, print all counts in the following order: lines, words, bytes.\n");
}

// 统计文件信息
void count_stats(FILE *file, const char *filename, int show_lines, int show_words, int show_bytes, int show_filename) {
    int lines = 0, words = 0, bytes = 0;
    int in_word = 0;
    int c;
    
    // 重置文件指针到开头
    rewind(file);
    
    while ((c = fgetc(file)) != EOF) {
        bytes++;
        
        // 统计行数（换行符）
        if (c == '\n') {
            lines++;
        }
        
        // 统计单词数（空白字符分割）
        if (isspace(c)) {
            if (in_word) {
                words++;
                in_word = 0;
            }
        } else {
            in_word = 1;
        }
    }
    
    // 处理文件末尾的单词
    if (in_word) {
        words++;
    }
    
    // 输出结果
    int output_count = 0;
    
    if (show_lines) {
        printf("%8d", lines);
        output_count++;
    }
    
    if (show_words) {
        printf("%8d", words);
        output_count++;
    }
    
    if (show_bytes) {
        printf("%8d", bytes);
        output_count++;
    }
    
    // 如果没有指定任何选项，输出所有统计信息
    if (!show_lines && !show_words && !show_bytes) {
        printf("%8d%8d%8d", lines, words, bytes);
        output_count = 3;
    }
    
    // 显示文件名
    if (show_filename && filename && strcmp(filename, "-") != 0) {
        printf(" %s", filename);
    }
    
    if (output_count > 0) {
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    int show_lines = 0;
    int show_words = 0;
    int show_bytes = 0;
    int show_help = 0;
    int read_stdin = 0;
    int file_count = 0;
    
    // 解析命令行参数
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            show_help = 1;
        } 
        else if (strcmp(argv[i], "-l") == 0 || strcmp(argv[i], "--lines") == 0) {
            show_lines = 1;
        } 
        else if (strcmp(argv[i], "-w") == 0 || strcmp(argv[i], "--words") == 0) {
            show_words = 1;
        } 
        else if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--bytes") == 0) {
            show_bytes = 1;
        } 
        else if (strcmp(argv[i], "-") == 0) {
            read_stdin = 1;
            file_count++;
        } 
        else if (argv[i][0] == '-') {
            // 处理组合选项（如 -lw, -lcw 等）
            for (int j = 1; argv[i][j]; j++) {
                switch (argv[i][j]) {
                    case 'l': show_lines = 1; break;
                    case 'w': show_words = 1; break;
                    case 'c': show_bytes = 1; break;
                    default:
                        fprintf(stderr, "Invalid option -- '%c'\n", argv[i][j]);
                        show_usage(argv[0]);
                        return 1;
                }
            }
        } 
        else {
            file_count++;
        }
    }
    
    // 显示帮助信息
    if (show_help) {
        show_usage(argv[0]);
        return 0;
    }
    
    // 如果没有文件参数，默认读取标准输入
    if (argc == 1 || (file_count == 0 && !read_stdin)) {
        read_stdin = 1;
        file_count++;
    }
    
    // 处理输入
    int total_lines = 0, total_words = 0, total_bytes = 0;
    int show_total = (file_count > 1);
    
    // 处理每个文件
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-") == 0 || (i == argc - 1 && read_stdin && file_count == 1)) {
            // 处理标准输入
            if (file_count > 1) {
                printf("standard input: ");
            }
            count_stats(stdin, "-", show_lines, show_words, show_bytes, file_count > 1);
            rewind(stdin); // 重置标准输入
            read_stdin = 0;
        } 
        else if (argv[i][0] != '-') {
            FILE *file = fopen(argv[i], "r");
            if (!file) {
                fprintf(stderr, "%s: %s: %s\n", argv[0], argv[i], strerror(errno));
                continue;
            }
            
            // 统计文件信息
            count_stats(file, argv[i], show_lines, show_words, show_bytes, file_count > 1);
            
            // 累加总计值
            fseek(file, 0, SEEK_END);
            long bytes = ftell(file);
            rewind(file);
            
            // 我们需要重新计算行数和单词数来累加
            int lines = 0, words = 0;
            int in_word = 0;
            int c;
            
            while ((c = fgetc(file)) != EOF) {
                if (c == '\n') {
                    lines++;
                }
                
                if (isspace(c)) {
                    if (in_word) {
                        words++;
                        in_word = 0;
                    }
                } else {
                    in_word = 1;
                }
            }
            
            if (in_word) {
                words++;
            }
            
            total_lines += lines;
            total_words += words;
            total_bytes += bytes;
            
            fclose(file);
        }
    }
    
    // 如果指定了多个文件，显示总计
    if (show_total) {
        int output_count = 0;
        
        if (show_lines) {
            printf("%8d", total_lines);
            output_count++;
        }
        
        if (show_words) {
            printf("%8d", total_words);
            output_count++;
        }
        
        if (show_bytes) {
            printf("%8d", total_bytes);
            output_count++;
        }
        
        // 如果没有指定任何选项，输出所有统计信息
        if (!show_lines && !show_words && !show_bytes) {
            printf("%8d%8d%8d", total_lines, total_words, total_bytes);
            output_count = 3;
        }
        
        if (output_count > 0) {
            printf(" total\n");
        }
    }
    
    return 0;
}