int key_finder(int **list, size_t listLen, int key)
{
	//Add your code here
	for (uint i = 0; i < listLen; i++)
	{
		if(list[i][0] == key)
		{
			return list[i][1];
		}
	}
	return -1;
}
