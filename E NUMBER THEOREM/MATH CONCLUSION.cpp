一些數學定理


Prime and Factors
	對於所有大於 1 的整數 n 都存在唯一一組質因數分解
		n = (p1^a1) * (p2^a2) * ... * (pk^ak)
	可以用質因數分解來算 n 有幾個因數
		t(n) = (a1+1) * (a2+1) * ... * (ak+1)
		note : t(12) = 6 --> 1, 2, 3, 4, 6, 12
	也可以用質因數分解來算 n 的因數和
		o(n) = ((p1^(a1+1)-1) / (p1-1)) * ((p2^(a2+1)-1) / (p2-1)) * ... * ((pk^(ak+1)-1) / (pk-1))
		note : o(12) = 1 + 2 + 3 + 4 + 6 + 12 = 28 = ((2^3-1)/(2-1)) * ((3^2-1)/(3-2)) = 7 * 4
	
	如果 n 不是質數，那 n 一定可以寫成兩個數字 a, b 相乘且 a, b 至少有一人一定介於 2 ~ sqrt(n) 之間
		可以 O(sqrt(n)) 找質數、質因數分解

	Euler's Theorem
		Euler's totient function : 給一個 n 求小於 n 且與 n 互質的數字有幾個
			Eut(n) = (p1^(a1-1) * (p1-1)) * (p2^(a2-1) * (p2-1)) * ... * (pk^(ak-1) * (pk-1))
			note : Eut(12) = 2^2 * 3 = (2^1)*1 * 3^0 * 2 = 4 --> {1, 5, 7, 11}
		Theorem
			x^(Eut(m)) % m = 1 (x 與 m 要互質)
		可以用來找模反元素
			inv(x in m) = x^(Eut(m)-1) % m

	Diophantine Equations
		ax + by = c 給 a, b, c，找一組整數解 (x, y)
		用 Extended Euclid's algorithm(Extended gcd) 找一組 (x, y)，那 (x + k * (b / gcd), y + k *(a / gcd)) 都會是整數解


