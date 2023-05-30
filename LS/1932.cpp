//���� Ǭ �ڵ�
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//std::vector<std::vector<int>> Vec = {};
//std::vector<int> Dp               = {};
//
//int Func(int a, int b, int layer)
//{
//	if (Vec.size() - 1 <= layer)
//	{
//		return 0;
//	}
//
//	int num       = max(a, b);
//	int nextLayer = layer + 1;
//
//	//Ǯ�ٰ� ��? �̷��� �� �׸��� �ƴѰ�?
//	return num + Func(Vec[nextLayer][0], Vec[nextLayer][1], nextLayer);
//}
//
//int main()
//{
//	int n = 0;
//
//	std::cin >> n;
//
//	Vec.resize(n);
//
//	for (size_t i = 0; i < n; ++i)
//	{
//		Vec[i].resize(i + 1);
//
//		for (size_t j = 0; j <= i; ++j)
//		{
//			std::cin >> Vec[i][j];
//		}
//	}
//
//	int result = Func(Vec[1][0], Vec[1][1], 1);
//
//	return 0;
//}

//���� ���� ������ �ڵ�
#include <iostream>
#include <vector>

using namespace std;

//�Է°�
std::vector<std::vector<int>> Vec = {};

int main()
{
	int n = 0;

	std::cin >> n;

	Vec.resize(n);

	for (size_t i = 0; i < n; ++i)
	{
		Vec[i].resize(i + 1);

		for (size_t j = 0; j <= i; ++j)
		{
			std::cin >> Vec[i][j];
		}
	}

	//�Ųٷ� ��ȸ
	for (int i = n - 1; i >= 1; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			Vec[i - 1][j] += max(Vec[i][j], Vec[i][j + 1]);
		}
	}

	std::cout << Vec[0][0] << std::endl;
}

//���
//ȥ�� 1�ð� ���� Ǯ�ٰ� �� �̻� �ð� ���� �� �ǹ̾��� �� ���Ƽ� ���� ���Ұ� �ڱ����� �������ϴ�.

//����� ��.
//1. ������ �� ��ġ�鼭 ū ���� ã�� �� �Ӹ��ӿ��� �� �ȱ׷���.
//2. �Ųٷ� ��ȸ�ؼ� �ֻ��� ��忡 ���� �дٴ� ���̵� �����س��� ����.
//-> Ǯ�鼭 Vector Dp�� ��ȸ�� ���� �� �־�� �� Sort �Լ��� �����Ϸ��� ����... 

//������ ��.
//1. Ǯ�鼭 �Է� ���� �� ������ �Է� �縸ŭ �迭�� ũ�⸦ ��ƾ� �ȴٰ� ������.
//->��� �׳� ũ�⸦ ���� ��Ƶΰ� �־�� �ε����θ� �����ϸ� ��.
//2. '���� ���� ������� Ǯ� DP����'��� �˰� ��.
