# Basics

### 初回起動時
`カスタマイズ`の`エクステンション`で、入っているエクステンションを全て有効にしておく

### 属性テーブルにExcelファイルの内容を追加
1. `ファイル`の`データの追加`の`データの追加`からExcelファイルを選ぶ
2. コンテンツウィンドウからポリゴンデータを含むレイヤを選択し右クリック、`属性の結合とリレート`から`結合`を選ぶ
  * 結合に利用する値を持つフィールドと、結合のマッチングに利用するフィールドのデータ型 (doubleとかstring)が同じでないといけない
  * 属性テーブルを開いて、列名の上でプロパティを開けば確認できる
  * リンクに使いたいコードがStringなら属性テーブルでフィールドをDoubleで追加、列名の上で右クリックして`フィールド演算`を選び、Pythonで`float(COLUMN_NAME)`として変換する <br>
追加した列名は、`データベース名$.列名`のようになっているので注意。エイリアスと名前は別物。

### エイリアスについて
属性テーブルにつけるエイリアスは便利だけれども、`データのエクスポート`でshpファイルにするとエイリアス情報が失われてしまう。エイリアス情報を保つには、`レイヤファイルとして保存`を使う。
