# 課題2 レポート
学籍番号　氏名


## 課題
長崎県にある市町村別人口データを読み込み、リスト構造にするプログラムを作成する。

1. 使用するデータ  
長崎県の人口データは、nagasaki.csvに保存されている。
nagasaki.csvには、csv形式で以下のデータが含まれる
- ID
- 県名
- 市町村名
- 人口
- 男性人口
- 女性人口

長崎県の市町村別人口データは、下記に構造体に読み込まれる。
```
typedef struct {
    int id;
    char pref[13];  // UTF-8対応
    char name[19];  // UTF-8対応
    int population;
    int m_population;
    int f_population;
} City;
```

英語版のデータを用意しました。名称は、nagasaki2.csvです。チャレンジ問題2で、一致する文字列が見つからない場合、こちらを利用してください。その場合、main関数内にあるfopenの引数を下記のように変更してください。
```    
fp = fopen("nagasaki2.csv","r");
```


1. 必須問題：実装する関数  
(1) InsertNewNode：必要なメモリを確保し、リストの先頭に新しいデータを挿入する。  
    [入力]
    - City newCity: リストに挿入する市町村のデータ
    - Node* pNext: リストの先頭アドレス  

    [出力]  
    - return値: (リストの先頭に新しいデータを挿入した後の)リストの先頭アドレス

    (2) SearchCityByID: IDをキーとし、リストを検索する。  
    [入力]  
    - Node* pList: リストの先頭アドレス
    - int ID: 検索する市町村のID 
    
    [出力]  
    - return値: IDが合致した場所(先頭を0とする)。IDが一致するデータがない場合は-1。  
    - City* pCity: IDが合致した市町村のデータを入れる

3. 補助関数  
以下の関数はすでに実装されており、利用することができる。  
- PrintCity: 市町村データを出力する
- ReleaseList: リストで確保したメモリを解放する
- PrintList: リストの内容を出力する。

4. チャレンジ問題  
(1) DeleteNodeAt: 任意のノードをリストから削除する(10点)  
CHALLENGE2を有効にしてください。  
    [入力]  
    - Node** ppNode: リストの先頭を指すポインタ変数のアドレス(ポインタのポインタ)  
    - int cn: ノードの位置(先頭のノードを0とする)  
    [出力]  
    - return値: 削除に成功したらSUCCESS、失敗したらERRR  

    (2) SearchCityByName: 市町村を名称で検索する(5点)  
    CHALLENGE1を有効にしてください。  
    [入力]
    - Node* pList: リストの先頭アドレス
    - char* cityName: 検索する市町村の名称

    [出力]  
    - return値: cityNameが合致した場所(先頭を0とする)。cityNameが一致するデータがない場合は-1。
    - City* pCity: IDが合致した市町村のデータを入れる

## ソースコードの説明
79: Node型の構造体 pNode を宣言し、pNodeのためのNodeのデータ領域を確保

80: pNode->city に newCity を代入

81: pNode->pNext に pNext を代入

82: pNext に pNode を代入

84: pNext を返す

92: int型の変数 x を宣言し、1を代入

93: Node型の構造体 pPrev を宣言

94: Node型の構造体 pNode を宣言

96: pNode に *ppNode を代入

97~102: cn が0の時に限り実行

98: pPrev に *ppNode を代入

99: pPrev に pNode->pNext を代入

100: *ppNode に pPrev を代入

102: pNode を解放

103~112: cn が0でない時は実行

104~108: x が cn 等しくない限り繰り返し実行

105: pPrev に pNode を代入

106: ppNode に &((*ppNode)->pNext) を代入

107: pNode に pNode->pNext を代入

108: x に1を加える

111: pPrev->pNext に pNode->pNext を代入

112: pNode を解放

115~116: *ppNode が NULL でない時に実行

116: 0を返す

117~118: *ppNode が NULL の時に実行

118: 1を返す

128: int型の変数 n, result を宣言し、result には-1を代入

129: Node型の構造体 pNode を宣言

131: pNode に pList を代入

132~139: n を0とし、n+1 が MAX_CITY より小さい限り繰り返し実行し、n に1を加える

133~136: pNode->city.name と cityName を比較し、一致したときは実行

134: *pCity に pNode->city を代入

135: result に n を代入

136: ループを抜ける

139: pNode に pNode->pNext を代入

142: result を返す

149: int型の変数 c, result を宣言し、result に-1を代入

150: Node型の構造体 pNode を宣言

152: pNode に pList を代入

153~160: c を0とし、c+1 が MAX_CITY より小さい限り繰り返し実行し、c に1を加える

154~157: pNode->city.id が ID と等しいとき実行

155: *pCity に pNode->city を代入

156: result に c を代入

157: ループを抜ける

160: pNode に pNode->pNext を代入

163: result を返す

## 出力結果
リストの最初以外のの要素を検索し削除
```
42201, NagasakiKen, Nagasaki, 429508, 198716, 230792
42202, NagasakiKen, Sasebo, 255439, 120198, 135241
42203, NagasakiKen, Shimabara, 45436, 20999, 24437
42204, NagasakiKen, Isahaya, 138078, 65029, 73049
42205, NagasakiKen, Omura, 92757, 43938, 48819
42207, NagasakiKen, Hirado, 31920, 14874, 17046
42208, NagasakiKen, Matsuura, 23309, 11164, 12145
42209, NagasakiKen, Tsushima, 31457, 15361, 16096
42210, NagasakiKen, Iki, 27103, 12860, 14243
42211, NagasakiKen, Goto, 37327, 17339, 19988
42212, NagasakiKen, Saikai, 28691, 14032, 14659
42213, NagasakiKen, Unzen, 44115, 20847, 23268
42214, NagasakiKen, MinamiShimabara, 46535, 21574, 24961
42307, NagasakiKen, Nagayo, 42548, 20090, 22458
42308, NagasakiKen, Togitsu, 29804, 14326, 15478
42321, NagasakiKen, HigashiSonogi, 8298, 3886, 4412
42322, NagasakiKen, Kawatana, 14067, 6656, 7411
42323, NagasakiKen, Hasami, 14891, 7079, 7812
42383, NagasakiKen, Ojika, 2560, 1172, 1388
42391, NagasakiKen, Sasa, 13626, 6426, 7200
42411, NagasakiKen, ShinKamigoto, 19718, 9197, 10521
===== Start Printing =====
42411, NagasakiKen, ShinKamigoto, 19718, 9197, 10521
42391, NagasakiKen, Sasa, 13626, 6426, 7200
42383, NagasakiKen, Ojika, 2560, 1172, 1388
42323, NagasakiKen, Hasami, 14891, 7079, 7812
42322, NagasakiKen, Kawatana, 14067, 6656, 7411
42321, NagasakiKen, HigashiSonogi, 8298, 3886, 4412
42308, NagasakiKen, Togitsu, 29804, 14326, 15478
42307, NagasakiKen, Nagayo, 42548, 20090, 22458
42214, NagasakiKen, MinamiShimabara, 46535, 21574, 24961
42213, NagasakiKen, Unzen, 44115, 20847, 23268
42212, NagasakiKen, Saikai, 28691, 14032, 14659
42211, NagasakiKen, Goto, 37327, 17339, 19988
42210, NagasakiKen, Iki, 27103, 12860, 14243
42209, NagasakiKen, Tsushima, 31457, 15361, 16096
42208, NagasakiKen, Matsuura, 23309, 11164, 12145
42207, NagasakiKen, Hirado, 31920, 14874, 17046
42205, NagasakiKen, Omura, 92757, 43938, 48819
42204, NagasakiKen, Isahaya, 138078, 65029, 73049
42203, NagasakiKen, Shimabara, 45436, 20999, 24437
42202, NagasakiKen, Sasebo, 255439, 120198, 135241
42201, NagasakiKen, Nagasaki, 429508, 198716, 230792
print list. items = 21
===== Print End =====
City ID?42207
the city was found at 15
42207, NagasakiKen, Hirado, 31920, 14874, 17046
City Name?Hirado
the city was found at 15
42207, NagasakiKen, Hirado, 31920, 14874, 17046
===== Start Printing =====
42411, NagasakiKen, ShinKamigoto, 19718, 9197, 10521
42391, NagasakiKen, Sasa, 13626, 6426, 7200
42383, NagasakiKen, Ojika, 2560, 1172, 1388
42323, NagasakiKen, Hasami, 14891, 7079, 7812
42322, NagasakiKen, Kawatana, 14067, 6656, 7411
42321, NagasakiKen, HigashiSonogi, 8298, 3886, 4412
42308, NagasakiKen, Togitsu, 29804, 14326, 15478
42307, NagasakiKen, Nagayo, 42548, 20090, 22458
42214, NagasakiKen, MinamiShimabara, 46535, 21574, 24961
42213, NagasakiKen, Unzen, 44115, 20847, 23268
42212, NagasakiKen, Saikai, 28691, 14032, 14659
42211, NagasakiKen, Goto, 37327, 17339, 19988
42210, NagasakiKen, Iki, 27103, 12860, 14243
42209, NagasakiKen, Tsushima, 31457, 15361, 16096
42208, NagasakiKen, Matsuura, 23309, 11164, 12145
42205, NagasakiKen, Omura, 92757, 43938, 48819
42204, NagasakiKen, Isahaya, 138078, 65029, 73049
42203, NagasakiKen, Shimabara, 45436, 20999, 24437
42202, NagasakiKen, Sasebo, 255439, 120198, 135241
42201, NagasakiKen, Nagasaki, 429508, 198716, 230792
print list. items = 20
===== Print End =====
free list. items = 20
```

リストの最初の要素を検索し削除
```
42201, NagasakiKen, Nagasaki, 429508, 198716, 230792
42202, NagasakiKen, Sasebo, 255439, 120198, 135241
42203, NagasakiKen, Shimabara, 45436, 20999, 24437
42204, NagasakiKen, Isahaya, 138078, 65029, 73049
42205, NagasakiKen, Omura, 92757, 43938, 48819
42207, NagasakiKen, Hirado, 31920, 14874, 17046
42208, NagasakiKen, Matsuura, 23309, 11164, 12145
42209, NagasakiKen, Tsushima, 31457, 15361, 16096
42210, NagasakiKen, Iki, 27103, 12860, 14243
42211, NagasakiKen, Goto, 37327, 17339, 19988
42212, NagasakiKen, Saikai, 28691, 14032, 14659
42213, NagasakiKen, Unzen, 44115, 20847, 23268
42214, NagasakiKen, MinamiShimabara, 46535, 21574, 24961
42307, NagasakiKen, Nagayo, 42548, 20090, 22458
42308, NagasakiKen, Togitsu, 29804, 14326, 15478
42321, NagasakiKen, HigashiSonogi, 8298, 3886, 4412
42322, NagasakiKen, Kawatana, 14067, 6656, 7411
42323, NagasakiKen, Hasami, 14891, 7079, 7812
42383, NagasakiKen, Ojika, 2560, 1172, 1388
42391, NagasakiKen, Sasa, 13626, 6426, 7200
42411, NagasakiKen, ShinKamigoto, 19718, 9197, 10521
===== Start Printing =====
42411, NagasakiKen, ShinKamigoto, 19718, 9197, 10521
42391, NagasakiKen, Sasa, 13626, 6426, 7200
42383, NagasakiKen, Ojika, 2560, 1172, 1388
42323, NagasakiKen, Hasami, 14891, 7079, 7812
42322, NagasakiKen, Kawatana, 14067, 6656, 7411
42321, NagasakiKen, HigashiSonogi, 8298, 3886, 4412
42308, NagasakiKen, Togitsu, 29804, 14326, 15478
42307, NagasakiKen, Nagayo, 42548, 20090, 22458
42214, NagasakiKen, MinamiShimabara, 46535, 21574, 24961
42213, NagasakiKen, Unzen, 44115, 20847, 23268
42212, NagasakiKen, Saikai, 28691, 14032, 14659
42211, NagasakiKen, Goto, 37327, 17339, 19988
42210, NagasakiKen, Iki, 27103, 12860, 14243
42209, NagasakiKen, Tsushima, 31457, 15361, 16096
42208, NagasakiKen, Matsuura, 23309, 11164, 12145
42207, NagasakiKen, Hirado, 31920, 14874, 17046
42205, NagasakiKen, Omura, 92757, 43938, 48819
42204, NagasakiKen, Isahaya, 138078, 65029, 73049
42203, NagasakiKen, Shimabara, 45436, 20999, 24437
42202, NagasakiKen, Sasebo, 255439, 120198, 135241
42201, NagasakiKen, Nagasaki, 429508, 198716, 230792
print list. items = 21
===== Print End =====
City ID?42411
the city was found at 0
42411, NagasakiKen, ShinKamigoto, 19718, 9197, 10521
City Name?ShinKamigoto
the city was found at 0
42411, NagasakiKen, ShinKamigoto, 19718, 9197, 10521
===== Start Printing =====
42391, NagasakiKen, Sasa, 13626, 6426, 7200
42383, NagasakiKen, Ojika, 2560, 1172, 1388
42323, NagasakiKen, Hasami, 14891, 7079, 7812
42322, NagasakiKen, Kawatana, 14067, 6656, 7411
42321, NagasakiKen, HigashiSonogi, 8298, 3886, 4412
42308, NagasakiKen, Togitsu, 29804, 14326, 15478
42307, NagasakiKen, Nagayo, 42548, 20090, 22458
42214, NagasakiKen, MinamiShimabara, 46535, 21574, 24961
42213, NagasakiKen, Unzen, 44115, 20847, 23268
42212, NagasakiKen, Saikai, 28691, 14032, 14659
42211, NagasakiKen, Goto, 37327, 17339, 19988
42210, NagasakiKen, Iki, 27103, 12860, 14243
42209, NagasakiKen, Tsushima, 31457, 15361, 16096
42208, NagasakiKen, Matsuura, 23309, 11164, 12145
42207, NagasakiKen, Hirado, 31920, 14874, 17046
42205, NagasakiKen, Omura, 92757, 43938, 48819
42204, NagasakiKen, Isahaya, 138078, 65029, 73049
42203, NagasakiKen, Shimabara, 45436, 20999, 24437
42202, NagasakiKen, Sasebo, 255439, 120198, 135241
42201, NagasakiKen, Nagasaki, 429508, 198716, 230792
print list. items = 20
===== Print End =====
free list. items = 20
```

リストの最後の要素を検索し削除
```
42201, NagasakiKen, Nagasaki, 429508, 198716, 230792
42202, NagasakiKen, Sasebo, 255439, 120198, 135241
42203, NagasakiKen, Shimabara, 45436, 20999, 24437
42204, NagasakiKen, Isahaya, 138078, 65029, 73049
42205, NagasakiKen, Omura, 92757, 43938, 48819
42207, NagasakiKen, Hirado, 31920, 14874, 17046
42208, NagasakiKen, Matsuura, 23309, 11164, 12145
42209, NagasakiKen, Tsushima, 31457, 15361, 16096
42210, NagasakiKen, Iki, 27103, 12860, 14243
42211, NagasakiKen, Goto, 37327, 17339, 19988
42212, NagasakiKen, Saikai, 28691, 14032, 14659
42213, NagasakiKen, Unzen, 44115, 20847, 23268
42214, NagasakiKen, MinamiShimabara, 46535, 21574, 24961
42307, NagasakiKen, Nagayo, 42548, 20090, 22458
42308, NagasakiKen, Togitsu, 29804, 14326, 15478
42321, NagasakiKen, HigashiSonogi, 8298, 3886, 4412
42322, NagasakiKen, Kawatana, 14067, 6656, 7411
42323, NagasakiKen, Hasami, 14891, 7079, 7812
42383, NagasakiKen, Ojika, 2560, 1172, 1388
42391, NagasakiKen, Sasa, 13626, 6426, 7200
42411, NagasakiKen, ShinKamigoto, 19718, 9197, 10521
===== Start Printing =====
42411, NagasakiKen, ShinKamigoto, 19718, 9197, 10521
42391, NagasakiKen, Sasa, 13626, 6426, 7200
42383, NagasakiKen, Ojika, 2560, 1172, 1388
42323, NagasakiKen, Hasami, 14891, 7079, 7812
42322, NagasakiKen, Kawatana, 14067, 6656, 7411
42321, NagasakiKen, HigashiSonogi, 8298, 3886, 4412
42308, NagasakiKen, Togitsu, 29804, 14326, 15478
42307, NagasakiKen, Nagayo, 42548, 20090, 22458
42214, NagasakiKen, MinamiShimabara, 46535, 21574, 24961
42213, NagasakiKen, Unzen, 44115, 20847, 23268
42212, NagasakiKen, Saikai, 28691, 14032, 14659
42211, NagasakiKen, Goto, 37327, 17339, 19988
42210, NagasakiKen, Iki, 27103, 12860, 14243
42209, NagasakiKen, Tsushima, 31457, 15361, 16096
42208, NagasakiKen, Matsuura, 23309, 11164, 12145
42207, NagasakiKen, Hirado, 31920, 14874, 17046
42205, NagasakiKen, Omura, 92757, 43938, 48819
42204, NagasakiKen, Isahaya, 138078, 65029, 73049
42203, NagasakiKen, Shimabara, 45436, 20999, 24437
42202, NagasakiKen, Sasebo, 255439, 120198, 135241
42201, NagasakiKen, Nagasaki, 429508, 198716, 230792
print list. items = 21
===== Print End =====
City ID?42201
the city was found at 20
42201, NagasakiKen, Nagasaki, 429508, 198716, 230792
City Name?Nagasaki
the city was found at 20
42201, NagasakiKen, Nagasaki, 429508, 198716, 230792
===== Start Printing =====
42411, NagasakiKen, ShinKamigoto, 19718, 9197, 10521
42391, NagasakiKen, Sasa, 13626, 6426, 7200
42383, NagasakiKen, Ojika, 2560, 1172, 1388
42323, NagasakiKen, Hasami, 14891, 7079, 7812
42322, NagasakiKen, Kawatana, 14067, 6656, 7411
42321, NagasakiKen, HigashiSonogi, 8298, 3886, 4412
42308, NagasakiKen, Togitsu, 29804, 14326, 15478
42307, NagasakiKen, Nagayo, 42548, 20090, 22458
42214, NagasakiKen, MinamiShimabara, 46535, 21574, 24961
42213, NagasakiKen, Unzen, 44115, 20847, 23268
42212, NagasakiKen, Saikai, 28691, 14032, 14659
42211, NagasakiKen, Goto, 37327, 17339, 19988
42210, NagasakiKen, Iki, 27103, 12860, 14243
42209, NagasakiKen, Tsushima, 31457, 15361, 16096
42208, NagasakiKen, Matsuura, 23309, 11164, 12145
42207, NagasakiKen, Hirado, 31920, 14874, 17046
42205, NagasakiKen, Omura, 92757, 43938, 48819
42204, NagasakiKen, Isahaya, 138078, 65029, 73049
42203, NagasakiKen, Shimabara, 45436, 20999, 24437
42202, NagasakiKen, Sasebo, 255439, 120198, 135241
print list. items = 20
===== Print End =====
free list. items = 20
```

リストの検索に失敗し、削除にも失敗
```
42201, NagasakiKen, Nagasaki, 429508, 198716, 230792
42202, NagasakiKen, Sasebo, 255439, 120198, 135241
42203, NagasakiKen, Shimabara, 45436, 20999, 24437
42204, NagasakiKen, Isahaya, 138078, 65029, 73049
42205, NagasakiKen, Omura, 92757, 43938, 48819
42207, NagasakiKen, Hirado, 31920, 14874, 17046
42208, NagasakiKen, Matsuura, 23309, 11164, 12145
42209, NagasakiKen, Tsushima, 31457, 15361, 16096
42210, NagasakiKen, Iki, 27103, 12860, 14243
42211, NagasakiKen, Goto, 37327, 17339, 19988
42212, NagasakiKen, Saikai, 28691, 14032, 14659
42213, NagasakiKen, Unzen, 44115, 20847, 23268
42214, NagasakiKen, MinamiShimabara, 46535, 21574, 24961
42307, NagasakiKen, Nagayo, 42548, 20090, 22458
42308, NagasakiKen, Togitsu, 29804, 14326, 15478
42321, NagasakiKen, HigashiSonogi, 8298, 3886, 4412
42322, NagasakiKen, Kawatana, 14067, 6656, 7411
42323, NagasakiKen, Hasami, 14891, 7079, 7812
42383, NagasakiKen, Ojika, 2560, 1172, 1388
42391, NagasakiKen, Sasa, 13626, 6426, 7200
42411, NagasakiKen, ShinKamigoto, 19718, 9197, 10521
===== Start Printing =====
42411, NagasakiKen, ShinKamigoto, 19718, 9197, 10521
42391, NagasakiKen, Sasa, 13626, 6426, 7200
42383, NagasakiKen, Ojika, 2560, 1172, 1388
42323, NagasakiKen, Hasami, 14891, 7079, 7812
42322, NagasakiKen, Kawatana, 14067, 6656, 7411
42321, NagasakiKen, HigashiSonogi, 8298, 3886, 4412
42308, NagasakiKen, Togitsu, 29804, 14326, 15478
42307, NagasakiKen, Nagayo, 42548, 20090, 22458
42214, NagasakiKen, MinamiShimabara, 46535, 21574, 24961
42213, NagasakiKen, Unzen, 44115, 20847, 23268
42212, NagasakiKen, Saikai, 28691, 14032, 14659
42211, NagasakiKen, Goto, 37327, 17339, 19988
42210, NagasakiKen, Iki, 27103, 12860, 14243
42209, NagasakiKen, Tsushima, 31457, 15361, 16096
42208, NagasakiKen, Matsuura, 23309, 11164, 12145
42207, NagasakiKen, Hirado, 31920, 14874, 17046
42205, NagasakiKen, Omura, 92757, 43938, 48819
42204, NagasakiKen, Isahaya, 138078, 65029, 73049
42203, NagasakiKen, Shimabara, 45436, 20999, 24437
42202, NagasakiKen, Sasebo, 255439, 120198, 135241
42201, NagasakiKen, Nagasaki, 429508, 198716, 230792
print list. items = 21
===== Print End =====
City ID?11111
sorry, the city was not found
City Name?a   
sorry, the city was not found
Segmentation fault
```
## 修正履歴
SearchCityByID と SearchCityByName の中の条件を n+1 <= MAX_CITY に変更しリストの最後の要素の検索及び削除が出来るように修正
