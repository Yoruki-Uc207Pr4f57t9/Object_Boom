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
#### 画像
##### 時限爆弾
![](./Doc/Images/boom0.png)
![](./Doc/Images/boom1.jpg)
![](./Doc/Images/boom2.jpg)
![](./Doc/Images/boom3.jpg)
#### 音
##### 爆発音_1
[countdown.wav](./Doc/Audio/countdown.wav)

### 素材処理
#### 画像編集ソフト
##### 時限爆弾
![](./Assets/Images/Boom[815x360].png)

    - 画像を ``Assets/Images`` フォルダに保存。
    - 画像の名前を ``Boom[815x360].png`` に変更。
    - 画像のサイズを ``815x360`` に変更。

##### 数字
![](./Assets/Images/Number[430x74][43x74_10].png)

    - 画像を ``Assets/Images`` フォルダに保存。
    - 画像の名前を ``Number[430x74][43x74_10].png`` に変更。
    - 画像のサイズを ``430x74`` に変更。
    - 画像を10等分し、1つの数字のサイズを ``43x74`` に変更。
    
##### 区切符（くぎりふ）
![](./Assets/Images/Separator[17x74].png)

    - 画像を ``Assets/Images`` フォルダに保存。
    - 画像の名前を ``Separator[17x74].png`` に変更。
    - 画像のサイズを ``17x74`` に変更。
    - 爆弾中の座標は ``(x=465, y=165)`` に配置。
    



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
