void fileW(){
	FILE *fp1=fopen("myfile.data","w");
	int i=123;float x=3.14159;
	fprintf(fp1,"%d,%5d,%5.3f\n",i,-i,x);
	fprintf(stdout,"%d,%5d,%5.3f\n",i,-i,x);
	fclose(fp1);
}
