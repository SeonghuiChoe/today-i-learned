# tsconfig in Docker

My project has a build script. It uses ``tsc``. I made Dockerfile but, I didn't copy tsconfig file. It ran tsc but, there wasn't tsconfig file so that there was an error.

```bash
Version 2.2.1
Syntax:   tsc [options] [file ...]

Examples: tsc hello.ts
          tsc --outFile file.js file.ts
          tsc @args.txt

Options:
 --allowJs                                          Allow javascript files to be compiled.
 ```