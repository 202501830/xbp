import random
print("弾丸ロシアンルーレットゲームスタート")
input()
for i in range(1,7): #コロンが入っていることに注意
    print(i,"回目の挑戦")
    input("引き金を引く")
    
    # ６個の弾倉のうち銃弾が入っている弾倉１個をランダムで決定
    bullet_position= random.randint(1, 6)
    current_position = 1

    if current_position == bullet_position:
        print("バンッ！！死んでしまった！")
        print("ゲームオーバー！！")
        break
    else:
        print("弾丸は入っていなかったようだ。あたり！")
        current_position=+1
else:
    print("すべてのロシアンルーレットに成功した！生還！！")

