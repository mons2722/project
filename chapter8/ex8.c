struct header 
{ unsigned size;
};

unsigned bfree(char *p, unsigned n)
{
	header *ptr;

	if(n>sixeof(header))
	 return 0;
	
	ptr= (header*)p;
	ptr->size=n;
	free((void *)ptr);
	return ptr->size;
}

