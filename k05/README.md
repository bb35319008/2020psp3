# 課題5 レポート
学生番号　氏名


## 課題
本課題では、以下の3つのプログラムを作成する。なお、出発駅、到着駅は、適宜変更しても良い。
- 赤迫駅を出発点として、深さ優先探索ですべての駅に到達可能なことを確認するプログラム。到達した駅名を出力するなど、各駅に1回到達したことを確認すること。  
- 赤迫駅を出発点として、幅優先探索ですべての駅に到達可能なことを確認するプログラム。到達した駅名を出力するなど、各駅に1回到達したことを確認すること。  
- 赤迫駅を出発点として、蛍茶屋駅までの最短所要時間ルートをダイクストラ法で見つけ、出力するプログラム
路線図、および、駅間の所要時間は下記のようになっている。  

1.使用するデータ  
路線図、及び、駅間の所要時間は下記のようになっている。なお、プログラムにおいて、駅名はArrayStation、グラフは隣接行列AdjacencyMatrixに保存されている。  

<img src=images/routemap.png width=600>  

```
typedef struct tagStation {
    char name[20];
    char kanji[16];
} Station;

Station ArrayStation[MAX_STATIONS] = {
    {"akasako", "赤迫"},
    {"nagasakidaigakumae", "長崎大学前"},
    {"nagasakiekimae", "長崎駅前"},
    {"shinchichukagai", "新地中華街"},
    {"ishibashi", "石橋"},
    {"sofukuji", "崇福寺"},
    {"shiminkaikan", "市民会館"},
    {"hotarujaya", "蛍茶屋"},
};

int AdjacencyMatrix[MAX_STATIONS][MAX_STATIONS] = {
    {0,  5,  0,  0,  0,  0,  0,  0},
    {5,  0, 16,  0,  0,  0,  0,  0},
    {0, 16,  0,  7,  0,  0,  5,  0},
    {0,  0,  7,  0,  7,  6, 10,  0},
    {0,  0,  0,  7,  0,  0,  0,  0},
    {0,  0,  0,  6,  0,  0, 10,  0},
    {0,  0,  5, 10,  0, 10,  0,  6},
    {0,  0,  0,  0,  0,  0,  6,  0},
};
```


2. 必須問題：実装する関数  
本課題では、以下の関数を実装する。  
(1) DepthFirstSearch: 深さ優先探索ですべての駅に到達可能なことを確認する  
    [入力]
    - int size: 駅の数　　
    - int matrix[size][size]: 隣接行列
    - int start: 出発駅のインデックス  

    [出力]  
    - なし。関数の出力はないが、関数内でprintf文を使うなど、すべての駅に到達可能なことをチェックすること。  


    (2) BreadthFirstSearch: 幅優先探索ですべての駅に到達可能なことを確認する  
    [入力]
    - int size: 駅の数　　
    - int matrix[size][size]: 隣接行列
    - int start: 出発駅のインデックス  

    [出力]  
    - なし。関数の出力はないが、関数内でprintf文を使うなど、すべての駅に到達可能なことをチェックすること。


3. 補助関数  
以下の関数はすでに実装されており、利用することができる。
- PrintStationName: indexで指定される駅名を出力する
- StackInit: スタックを初期化する
- StackPush: スタックに値をプッシュする
- StackPop: スタックから値をポップする
- StackTop: スタックの先頭の値を取得する(スタックポインタは移動しない)
- StackIsEmpty: スタックが空か判断する。空の場合はTRUE、空でなければFALSEを返す。
- InitQueue: キューを初期化する
- EnQueue: キューに値を入れる
- DeQueue: キューから値を取り出す
- QueueIsEmpty: キューが空か判断する。空の場合はTRUE、空でなければFALSEを返す。
- main: メイン関数。深さ優先探索、幅優先探索、ダイクストラ法による最短経路探索処理を呼び出す。

4. チャレンジ課題  
    (1) 赤迫駅を起点として、各駅にたどり着くまでのルートを、深さ優先探索、幅優先探索のそれぞれの場合で出力するようにプログラムを修正する。  
   - 深さ優先探索のルート表示(10点)
   - 幅優先探索のルート表示(10点)

    (2) SearchGraphByDijkstra: ダイクストラ法で、出発駅から到着駅までの最短所要時間ルートを探索する(20点)。  
    [入力]  
    - int start: 出発駅のインデックス
    - int goal: 到着駅のインデックス  
    - int size: 駅数  
    - int matrix[size][size]: 隣接行列  
    - NodeInfo arrayNodeInfo[size]:  

    [出力]  
    - return値: 出発駅から到着駅までの所要時間 
    - 関数内でprintf文を使い、最短ルートを出力すること


## ソースコードの説明
109: int型の配列 visited[size] と変数 i, j を宣言

111~113: i を0とし、i が size より小さい限り以下を繰り返し実行し、i に1を代入

112: visited[i] に0を代入(viaited を初期化)

115: スタックを初期化

116: スタックに出発点の index を入れる

118: ===== 深さ優先探索で到達した駅 =====\n を出力

119~132: スタックが空か判断し、空でない限り以下を繰り返し実行

120: i にスタックから値をポップ

121: j に0を代入

122~131: visited[i] が1でない時は以下を実行

123: visited[i] に1を代入(行ったことにする)

124: 駅の名前を出力(到達した駅が分かるようにするため)

125~130: j が size より小さい限り以下を繰り返し実行

126~128: matrix[i][j] が0でない時は以下を実行

127: スタックに j をプッシュ

129: j に1を加算

134: 返す

200: int型の配列 visited[size] と変数 i, j を宣言

202~204: i を0とし、i が size より小さい限り以下を繰り返し実行し、i に1を代入

203: visited[i] に0を代入(viaited を初期化)

206: キューを初期化

207: キューに出発点の index を入れる

209: ===== 幅優先探索で到達した駅 =====\n を出力

210~223: キューが空か判断し、空でない限り以下を繰り返し実行

211: i にキューから値を取り出す

212: j に0を代入

213~222: visited[i] が1でない時は以下を実行

214: visited[i] に1を代入(行ったことにする)

215: 駅の名前を出力(到達した駅が分かるようにするため)

216~221: j が size より小さい限り以下を繰り返し実行

217~219: matrix[i][j] が0でない時は以下を実行

218: キューに j を入れる

220: j に1を加算

225: 返す

## 出力結果

```
===== 深さ優先探索で到達した駅 =====
赤迫
長崎大学前
長崎駅前
市民会館
蛍茶屋
崇福寺
新地中華街
石橋
===== 幅優先探索で到達した駅 =====
赤迫
長崎大学前
長崎駅前
新地中華街
市民会館
石橋
崇福寺
蛍茶屋
Time Required: 8
```

## 修正履歴

