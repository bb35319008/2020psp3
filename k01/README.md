# 課題1 レポート
35319008　五輪慧大


## 課題
長崎県にある市町村別人口データを読み込み、IDを用いて検索し、該当する市町村名、人口を出力するプログラムを作成する。

1. 使用するデータ
長崎県の人口データは、nagasaki.csvに保存されている。
nagasaki.csvには、csv形式で以下のデータが含まれる
    - ID
    - 県名
    - 市町村名
    - 人口
    - 男性人口
    - 女性人口

    長崎県の市町村別人口データは、下記に構造体の配列に読み込まれる。

```C: 市町村別データ構造体
typedef struct {  
    int id;  
    char pref[13];  // UTF-8対応  
    char name[19];  // UTF-8対応  
    int population;  
    int m_population;  
    int f_population;  
} City;  
```



2. 必須問題：実装する関数  
本課題では、以下の関数を実装する。  
   (1) LinearSearch：IDをキーとし、リニアサーチで市町村を検索する。  
    [入力]
    - int key: 検索する市町村のID
    - City arrayCity[]: 検索対象の都市別人口データ(配列)
    - int size: データの数  

    [出力]  
    - return値: IDが合致した配列データのindex。IDが一致するデータがない場合は-1。

    (2) BinarySearch: IDをキーとし、バイナリサーチで市町村を検索する。  
    [入力]
    - int key: 検索する市町村のID
    - City arrayCity[]: 検索対象の都市別人口データ(配列)
    - int left: バイナリサーチを行う配列のindex(左端)
    - int right: バイナリサーチを行う配列のindex(右端)  

    [出力]  
    - return値: IDが合致した配列データのindex。IDが一致するデータがない場合は-1。


3. 補助関数
以下の関数はすでに実装されており、利用することができる。  
- PrintCity: 特定の市町村別人口データを出力する  
- PrintArray: 市町村別人口データをすべて出力する  
- LoadData: 市町村別人口データを読み込み、City型の配列に格納する  
- main: メイン関数。データをロードし、リニアサーチ、バイナリサーチを呼び出す  


## ソースコードの説明

68: int型の変数 i, index を宣言

70: indexに-1を代入

71: i=0, i < size, i++ という条件で繰り返し処理

72: keyがarrayCity[i].idと等しいときindexにiを代入しループから抜ける

78: indexを返す

84: int型の変数 pos, index を宣言

86: indexに-1を代入

87: leftに0を代入

88: rightにMAX_CITY - 1を代入

89: left <= right という条件を満たす限り繰り返し処理

90: pos に left + (right - left) / 2 を代入

91: keyがarrayCity[pos].idより小さいときrightに pos - 1 を代入

93: keyがarrayCity[pos].idより大きいときleftに pos + 1 を代入

95: 今までの条件を満たさない場合、indexにposを代入しループ処理を抜ける

101: indexを返す

## 出力結果

IDがあった場合
```
42201, 長崎県, 長崎市, 429508, 198716, 230792
42202, 長崎県, 佐世保市, 255439, 120198, 135241
42203, 長崎県, 島原市, 45436, 20999, 24437
42204, 長崎県, 諫早市, 138078, 65029, 73049
42205, 長崎県, 大村市, 92757, 43938, 48819
42207, 長崎県, 平戸市, 31920, 14874, 17046
42208, 長崎県, 松浦市, 23309, 11164, 12145
42209, 長崎県, 対馬市, 31457, 15361, 16096
42210, 長崎県, 壱岐市, 27103, 12860, 14243
42211, 長崎県, 五島市, 37327, 17339, 19988
42212, 長崎県, 西海市, 28691, 14032, 14659
42213, 長崎県, 雲仙市, 44115, 20847, 23268
42214, 長崎県, 南島原市, 46535, 21574, 24961
42307, 長崎県, 長与町, 42548, 20090, 22458
42308, 長崎県, 時津町, 29804, 14326, 15478
42321, 長崎県, 東彼杵町, 8298, 3886, 4412
42322, 長崎県, 川棚町, 14067, 6656, 7411
42323, 長崎県, 波佐見町, 14891, 7079, 7812
42383, 長崎県, 小値賀町, 2560, 1172, 1388
42391, 長崎県, 佐々町, 13626, 6426, 7200
42411, 長崎県, 新上五島町, 19718, 9197, 10521

===== linear search =====
City ID?42383
42383, 長崎県, 小値賀町, 2560, 1172, 1388

===== binary search =====
City ID?42383
42383, 長崎県, 小値賀町, 2560, 1172, 1388
```

IDが無かった場合
```
42201, 長崎県, 長崎市, 429508, 198716, 230792
42202, 長崎県, 佐世保市, 255439, 120198, 135241
42203, 長崎県, 島原市, 45436, 20999, 24437
42204, 長崎県, 諫早市, 138078, 65029, 73049
42205, 長崎県, 大村市, 92757, 43938, 48819
42207, 長崎県, 平戸市, 31920, 14874, 17046
42208, 長崎県, 松浦市, 23309, 11164, 12145
42209, 長崎県, 対馬市, 31457, 15361, 16096
42210, 長崎県, 壱岐市, 27103, 12860, 14243
42211, 長崎県, 五島市, 37327, 17339, 19988
42212, 長崎県, 西海市, 28691, 14032, 14659
42213, 長崎県, 雲仙市, 44115, 20847, 23268
42214, 長崎県, 南島原市, 46535, 21574, 24961
42307, 長崎県, 長与町, 42548, 20090, 22458
42308, 長崎県, 時津町, 29804, 14326, 15478
42321, 長崎県, 東彼杵町, 8298, 3886, 4412
42322, 長崎県, 川棚町, 14067, 6656, 7411
42323, 長崎県, 波佐見町, 14891, 7079, 7812
42383, 長崎県, 小値賀町, 2560, 1172, 1388
42391, 長崎県, 佐々町, 13626, 6426, 7200
42411, 長崎県, 新上五島町, 19718, 9197, 10521

===== linear search =====
City ID?42222
city was not found

===== binary search =====
City ID?42222
city was not found
```
## 修正履歴

main関数の中でLoadDataを実行しているので関数LinearSearchと関数BinarySearchの中にあったLoadDataを削除