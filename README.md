tcshutwindown パッケージ
========================

Windowsをシャットダウンする。それだけ。

### 前提環境

  * TeXエンジン： LuaTeX 1.10版以降
  * フォーマット： LaTeX／plain TeX
  * OS： Windows XP以降

### インストール

TDS 1.1に従うシステムの場合、以下のように配置する。
`$TEXBIN`は`luatex.exe`のあるディレクトリ。

  - `tcshutwindown.sty` → `$TEXMF/tex/lualatex/tcshutwindown`
  - `shutwindown.dll`   → `$TEXBIN/lib/lua`

※64ビット版のLuaTeXを使う場合は、`win64/`以下にある`shutwindown.dll`を
代わりに`$TEXBIN/lib/lua`に配置する。この場合の`$TEXBIN`は64ビット版の
`luatex.exe`のある場所である。

### 使用法

#### LaTeXの場合

プレアンブル中に次の記述を行う。

    \usepackage[grace=<整数>]{tcshutwindown}

`<整数>`はシャットダウン開始までの猶予時間（秒単位）。

#### plainの場合

    \def\ShutdownGraceSeconds{<整数>}
    \input tcshutwindown.sty

更新履歴
--------

  * Version 0.3  ‹2019/06/12›
      - Lua 5.3版用に書き直した。
  * Version 0.2  ‹2012/12/18›
      - 最初の公開版。

--------------------
Takayuki YATO (aka. "ZR")  
https://github.com/zr-tex8r
