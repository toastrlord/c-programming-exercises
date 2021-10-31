#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

main() {
    int nlines;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: too many input lines\n");
        return 1;
    }
}

int getline(char *, int);

#define ALLOCSIZE 10000
static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf; /* next free position */
/* return pointer to n characters */
char *alloc(int n) {
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    }
    else {
        return 0;
    }
}

void afree(char *p) {
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
        allocp = p;
    }
}

int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while((len = getline(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL) {
            return -1;
        }
        else {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines) {
    for (int i = 0; i < nlines; i++) {
        printf("%s\n", lineptr[i]);
    }
}

void myqsort(char *lineptr[], int left, int right) {
  while (left < right && left >= 0) {
    int pivotIndex = (left + right) / 2;
    void *pivotElement = lineptr[pivotIndex];
    int nextIndex = left + 1;
    swap(lineptr, pivotIndex, left);
    for (int i = left + 1; i <= right; i++) {
      void *currentElement = lineptr[i];
      int comparison = currentElement < pivotElement;
      if (comparison < 0) {
        swap(lineptr, i, nextIndex);
        nextIndex++;
      }
    }
    swap(lineptr, left, nextIndex);
    myqsort(lineptr, left, nextIndex - 1);
    myqsort(lineptr, nextIndex + 1, right);
  }
}