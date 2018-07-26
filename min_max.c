int exam_q6(int *list, int size, int *minimum, int *maximum)
{
	*minimum = list[0];
	*maximum = list[0];

	for(int i = 0; i < size; i++)
	{
		if(list[i] < *minimum)
		{
			*minimum = list[i];
		}
		if(list[i] > *maximum)
		{
			*maximum = list[i];
		}
	}


	return 0;

}
