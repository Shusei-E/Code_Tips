# Beamer-Poster
Make poster with [latex-beamerposter](https://github.com/deselaers/latex-beamerposter) package. The original template can be found [here](http://www.latextemplates.com/template/dreuw-deselaers-poster).  
Modified style files are:

1. [Original with slight modification](https://gist.github.com/Shusei-E/0c13b64ac31d8fc2cce395e2f892325e)
2. [Left aligned title](https://gist.github.com/Shusei-E/39d6d5bc86f46acf2b1b6fc06193aa91)


# Table of Contents
1. [Graphics related error such as BoundingBox](#graphics-related-error-such-as-boundingbox)
2. [Manually insert a subtitle](#manually-insert-a-subtitle)
3. [Hyphenation](#hyphenation)
4. [Change box depth](#change-box-depth)
5. [Hilight](#hilight)
6. [Insert Code](#insert-code)

## Graphics related error such as BoundingBox
Set `dvipdfmx` option in document class. `\documentclass[dvipdfmx, final,hyperref={pdfpagelabels=false}]{beamer}`  
[Reference](http://qiita.com/zr_tex8r/items/442b75b452b11bee8049)

## Manually insert a subtitle
Comment out `\usebeamercolor{title in headline}{\color{fg}\textbf{\Large{YOUR SUBTITLE}}\\[1ex]}` in the style file.  
The sample stylefile is [here](https://gist.github.com/Shusei-E/39d6d5bc86f46acf2b1b6fc06193aa91).

## Hyphenation
Add the following in `.tex` or `.sty`.
```tex
% Hyphenation
\usepackage{ragged2e}
\let\raggedright=\RaggedRight
```
Please note that hyphenation seems to work in `itemize`.

## Change box depth
Edit style file. Probably `beamercolorbox` `dp` option. ([reference](https://sites.google.com/site/mymemoryforfuture/tex/beamer))  
Should we change `ht`??

## Hilight
Preamble:
```tex
% Highlight
\usepackage{soul} 
\usepackage{etoolbox}
\makeatletter
\patchcmd{\SOUL@ulunderline}{\dimen@}{\SOUL@dimen}{}{}
\patchcmd{\SOUL@ulunderline}{\dimen@}{\SOUL@dimen}{}{}
\patchcmd{\SOUL@ulunderline}{\dimen@}{\SOUL@dimen}{}{}
\newdimen\SOUL@dimen
\makeatother
\makeatletter 
\newcommand\Oricolor{% 
  \let\set@color\beamerorig@set@color 
  \let\reset@color\beamerorig@reset@color 
  } 
\makeatother
```
In text:
```tex
\begin{itemize}
	\item  {\Oricolor\hl{This is the test sentence for soul}} 
\end{itemize}
```
[Reference](http://tex.stackexchange.com/questions/302081/soul-package-doesnt-work-in-beamer-with-existing-solution)

## Insert Code
Be careful with
* `\end{frame}` can NOT be indented
* `\end{frame}` cannot have any comments directly after it

Changing this line fixed the error.

If the above does not work, try [this](http://tex.stackexchange.com/questions/73366/a-line-in-the-lstlisting-environment-cannot-start-with-endframe-in-a-beamer):
```tex
\documentclass{beamer}%
\usepackage{listings}%
\newsavebox{\codebox}% For storing listings

\begin{document}

\begin{lrbox}{\codebox}
\begin{lstlisting}
Your code
\end{lstlisting}
\end{lrbox}

\begin{frame}
\usebox{\codebox}
\end{frame}

\end{document}​
```
