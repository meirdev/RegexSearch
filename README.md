## Search

Small program for search in files, multi-thread support.

![](https://raw.githubusercontent.com/meirdev/XSearch/master/Assets/Picture.png)

### Usage

```
X-Search
Usage: ./XSearch [OPTIONS] term [dir] [match]

Positionals:
  term TEXT REQUIRED          Term to search
  dir TEXT                    Search in directroy
  match TEXT                  Filename match

Options:
  -h,--help                   Print this help message and exit
  -B,--before-context UINT    Print NUM lines of leading context before matching lines
  -A,--after-context UINT     Print NUM lines of trailing context after matching lines
  -i,--ignore-case            Ignore case distinctions in PATTERN
  -e,--regexp                 Interpret PATTERNS as extended regular expressions
  -t,--type TEXT ...          File types to search
  -r,--recursive              Read all files under each directory, recursively
```