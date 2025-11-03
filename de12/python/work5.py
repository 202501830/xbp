for i in range(1,4): #コロンが入っていることに注意 #()内の数字は1,3打つと3は含まれない
    print(i,"人目")#タブでずらしていることに注意！
    name=input("名前を教えて下さい")
    waist=float(input("腹囲は？"))
    age=int(input("年齢は？"))

    print(name, "さんは腹囲", waist, "cmで年齢は",age, "才ですね。")
#条件定義後に:を付け忘れないよう注意
#intは整数、strは文字
    if waist>=90 and age>=50:
        print(name,"さん、内臓脂肪蓄積注意です")
    else:
        print(name,"さん、腹囲は問題ありません")