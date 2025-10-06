# Object_Boom

## ゲームについて
### ゲーム説明
本作は時限爆弾解除ゲームです。プレイヤーは制限時間内に正しいパスワードを入力し、爆弾を解除しなければなりません。
 - 爆弾のパスワード針は常に回転しています。
 - 数字のエリア上でスペースキーを押すことで、その数字を入力できます。
 - パスワードが完全に一致すれば爆弾解除成功。
 - 入力を間違えるとカウントダウンが加速し、さらにそれまでの入力をやり直さなければなりません。
 - パスワードは状況によって変化する場合もあります。

### 素材
#### 爆弾
![](./Doc/Images/boom0.png)
![](./Doc/Images/boom1.jpg)
![](./Doc/Images/boom2.jpg)
![](./Doc/Images/boom3.jpg)

## プログラムについて
### コンパイラの「インクルードパス」を設定
``include/`` 配下のヘッダーファイルを直接見つけられるようにする：

 1. プロジェクトを右クリック → ``Properties``（プロパティ）。
 2. 左ペインで ``Configuration Properties → C/C++ → General`` を選択。
 3. Additional Include Directories に次を追加：
```
$(ProjectDir)include;
```

``$(ProjectDir)`` マクロを使うと、絶対パスのハードコードを避けられます。階層が深い場合は ``$(SolutionDir)libs\engine\include`` などに変更してください。
左上の **Configuration** は **「All Configurations」、Platform** は **「All Platforms」** を選択すると、**Debug/Release、Win32/x64** の両方に適用されます。
