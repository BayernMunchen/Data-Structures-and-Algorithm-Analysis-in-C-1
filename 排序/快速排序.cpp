/*
 * ����Ԫ�ء�
 */
void Swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/*
������ŦԪ��
*/
ElementType Median(ElementType A[], int Left, int Right)
{
	int Center = (Left + Right) / 2;

	if (A[Left] > A[Center])
		Swap(&A[Left], &A[Center]);
	if (A[Left] > A[Right])
		Swap(&A[Left], &A[Right]);
	if (A[Center] > A[Right])
		Swap(&A[Left], &A[Right]);

	Swap(&A[Center], &A[Right]);
	return A[Right];
}

/*
��������
*/
void Qsort(ElementType A[], int Left, int Right)
{
	int i, j;
	ElementType pivot;

	//֮ǰ�˴����û��if�жϣ����³�������޷����У�
	//��Ϊ�ݹ�ĳ���û�г���,����ѭ�������Լ���
	if (Left + Cutoff >= Right)
	{	//��Ҫ��������ݸ�������3��ʱʹ�ÿ�������
		//���ѭ��ֱ��i<jʱ������ѭ��������iλ��Ԫ������ŦԪ��
		//���򣬱�iλ�ô��Ԫ�����jλ��С��Ԫ�ؽ��н���
		pivot = Median(A, Left, Right);
		i = Left;
		j = Right - 1;
		for (; ; )
		{
			while (A[++i] < pivot) {}
			while (A[++j] > pivot) {}
			if (i < j)
				Swap(&A[i], &A[j]);
			else
				break;
		}
		Swap(&A[i], &A[Right - 1]);

		//�ݹ�ĶԱ���ŦԪ��С�ͱ���ŦԪ�ش����ݽ��п�������
		Qsort(A, Left, i - 1);
		Qsort(A, i + 1, Right);
	}
	else
		//��Ҫ��������ݸ�������3��ʱʹ��ֱ�Ӳ�������Ч�ʸ��ڿ�������
		InsertionSort(A + Left, Right - Left + 1);
}



int main()
{
	int b[10];
	int i;
	int a[10] = { 2, 4, 67, 12, 43, 78, 5, 3, 8, 87};

	Qsort(a, 0, 9);
	for (i = 0; i < 10; i++)
		printf("%d,", a[i]);

    return 0;
}

