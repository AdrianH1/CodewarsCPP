#define ll long long

ll dontGiveMeFive(ll start, ll end)
{

	return 0;
}

int main()
{
    // small_numbers
    dontGiveMeFive(-17, 9); //Equals(24));
    dontGiveMeFive(1, 9); //Equals(8));
    dontGiveMeFive(4, 17); //Equals(12));
    dontGiveMeFive(-17, -4); //Equals(12));
    // larger_numbers
    dontGiveMeFive(984, 4304); //Equals(2449));
    dontGiveMeFive(2313, 2317); //Equals(4));
    dontGiveMeFive(-4045, 2575); //Equals(4819));
    dontGiveMeFive(-4436, -1429); //Equals(2194));
    // huge_numbers
    dontGiveMeFive(40076, 2151514229639903569); //Equals(326131553237897713));
    dontGiveMeFive(-206981731, 2235756979031654521); //Equals(340132150309630357));
    dontGiveMeFive(-2490228783604515625, -2490228782196537011); //Equals(520812180));
    dontGiveMeFive(-9000000000000000000, 9000000000000000000); //Equals(2401514164751985937));
    // edge_cases
    dontGiveMeFive(0, 1); //Equals(2));
    dontGiveMeFive(5, 15); //Equals(9));
    dontGiveMeFive(-5, 4); //Equals(9));
    dontGiveMeFive(51, 60); //Equals(1));
	return 0;
}