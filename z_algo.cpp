voidz_algo(const char*s,int*z){
 intn=strlen(s), left=0,right =0;
 for(inti=1;i<n;i++){
 if(i>right) {
 left=right=i;
 while(right<n&&s[right-left]==s[right])
 right++;
 z[i]=right-left;right--;
 }elseif(z[i-left]<right–i+1)
 z[i]=z[i-left];
 else{ left =i;
 while(right<n&&s[right-left]==s[right])
 right++;
 z[i]=right-left;right--;
 }
 }
 }

 intz_app(constchar*t,constchar*p){
 //Taoxaumois
 intp_size =strlen(p),t_size=strlen(t);
 chars[p_size+t_size+2];
 strcpy(s,p);
 strcat(s,"$");//'$'khongcotrongpvat
 strcat(s,t);
 intn=strlen(s), z[n]={0},count=0;
 z_algo(s,z);//TaomangzbangthuattoanZ
 //Demsolanxuathiencuaptrongt
 for(inti =0;i<n;i++) {
 if(z[i] ==p_size){
 count++;
 }
 }
 returncount;
 }
