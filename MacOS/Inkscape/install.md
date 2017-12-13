# Install

## Latex Plug-in
Use [textext](https://pav.iki.fi/software/textext/).

### postoedit
```terminal
$ brew install pstoedit
```
### texttext
Download `tar.gz` from the website. Move `textext.inx` and `textext.py` to `~/.config/inkscape/extensions/`.

### Put symbolic link
By creating symolic link, you can use `cd` command.
```terminal
$ ln -s /Library/TeX/texbin/pdflatex /usr/local/bin/
```
You can find pdflatex by
```terminal
$ which pdflatex
```
You need to restart the application (including X11).

### Setting
Prepare `textext.ini`
```
\usepackage{amsmath}
\usepackage{amsfonts}
```

### Alternative option
Use LaTexiT and save as `.svg`. `brew install pdf2svg` is required.