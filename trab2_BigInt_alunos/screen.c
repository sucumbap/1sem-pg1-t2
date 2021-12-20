#include <pg/pglib.h>
#define MAX_WIDTH   1135 
#define  MAX_HEIGHT   450 

void graph_base() {
	graph_init2("7 Segments Display", MAX_WIDTH, MAX_HEIGHT);
	graph_rect(5,225,108,220,c_lightblue,true);    
	graph_rect(118,225,108,220,c_lightblue,true);  
	graph_rect(231,225,108,220,c_lightblue,true);  
	graph_rect(344,225,108,220,c_lightblue,true);  
	graph_rect(457,225,108,220,c_lightblue,true);  
	graph_rect(570,225,108,220,c_lightblue,true);  
	graph_rect(683,225,108,220,c_lightblue,true);  
	graph_rect(796,225,108,220,c_lightblue,true);  
	graph_rect(909,225,108,220,c_lightblue,true);  
	graph_rect(1022,225,108,220,c_lightblue,true);  
	graph_rect(5,5,36,73.3,c_lightblue,true);    
	graph_rect(46,5,36,73.3,c_lightblue,true);   
	graph_rect(87,5,36,73.3,c_lightblue,true);   
	graph_rect(128,5,36,73.3,c_lightblue,true);  
	graph_rect(169,5,36,73.3,c_lightblue,true);  
	graph_rect(210,5,36,73.3,c_lightblue,true);  
	graph_rect(251,5,36,73.3,c_lightblue,true);  
	graph_rect(292,5,36,73.3,c_lightblue,true);  
	graph_rect(333,5,36,73.3,c_lightblue,true);  
	graph_rect(374,5,36,73.3,c_lightblue,true);  
}
int main()
{
int array_de_algarismos[10];
int n;
int d = 1;
	printf("Numero entre 0 e 2147483647: ");
	scanf("%d",&n);
if(n >= 0 && n <= 2147483647{

while(d <= 10) 
	{
		array_de_algarismos[10 - d] = n%10;
		n = n/10;
		d++; 
	}
		
	graph_base();
				
		int xM1 = 21.2, xM2 = 96.8, xM3 = 10.4, x1, x2, x3;
		int xim1 = 10.4, xim2 = 35.6, xim3 = 6.8, xm1, xm2, xm3;
		
		for(int i=0; i<=9; i++) {
			x1=xM1 + (i*113);   
			x2=xM2 + (i*113);
			x3=xM3 + (i*113);   
			xm1 = xim1 + (i*41);  
			xm2 = xim2 + (i*41);
			xm3 = xim3 + (i*41);  
			if(array_de_algarismos[i]==0) {
				graph_rect(x1,236,75.6,10.8,c_blue,true);     
				graph_rect(x2,246.8,10.8,82.8,c_blue,true);     
				graph_rect(x2,340.4,10.8,82.8,c_blue,true);    
				graph_rect(x1,423.2,75.6,10.8,c_blue,true);
				graph_rect(x3,340.4,10.8,82.8,c_blue,true);  
				graph_rect(x3,246.8,10.8,82.8,c_blue,true);  
				graph_rect(x1,329.6,75.6,10.8,c_white,true); 
				graph_rect(xm1, 8.665, 25.2, 3.6, c_blue,true);       
				graph_rect(xm2, 12.265, 3.6, 27.585, c_blue,true);      
				graph_rect(xm2, 43.45, 3.6, 27.585, c_blue,true);       
				graph_rect(xm1, 71.035, 25.2, 3.6, c_blue,true);      
				graph_rect(xm3, 43.45, 3.6, 27.585, c_blue,true);     
				graph_rect(xm3, 12.265 ,3.6 ,27.585 ,c_blue,true);    
				graph_rect(xm1, 39.85, 25.2, 3.6, c_white,true);      				
			}
			if(array_de_algarismos[i]==1) {
				graph_rect(x1,236,75.6,10.8,c_white,true);   
				graph_rect(x2,246.8,10.8,82.8,c_blue,true);  
				graph_rect(x2,340.4,10.8,82.8,c_blue,true);   
				graph_rect(x1,423.2,75.6,10.8,c_white,true); 
				graph_rect(x3,340.4,10.8,82.8,c_white,true); 
				graph_rect(x3,246.8,10.8,82.8,c_white,true); 
				graph_rect(x1,329.6,75.6,10.8,c_white,true); 
				graph_rect(xm1, 8.665, 25.2, 3.6, c_white,true);       
				graph_rect(xm2, 12.265, 3.6, 27.585, c_blue,true);      
				graph_rect(xm2, 43.45, 3.6, 27.585, c_blue,true);       
				graph_rect(xm1, 71.035, 25.2, 3.6, c_white,true);     
				graph_rect(xm3, 43.45, 3.6, 27.585, c_white,true);     
				graph_rect(xm3, 12.265 ,3.6 ,27.585 ,c_white,true);    
				graph_rect(xm1, 39.85, 25.2, 3.6, c_white,true);      
			}
			if(array_de_algarismos[i]==2) {
				graph_rect(x1,236,75.6,10.8,c_blue,true);    
				graph_rect(x2,246.8,10.8,82.8,c_blue,true);   
				graph_rect(x2,340.4,10.8,82.8,c_white,true); 
				graph_rect(x1,423.2,75.6,10.8,c_blue,true);  
				graph_rect(x3,340.4,10.8,82.8,c_blue,true);  
				graph_rect(x3,246.8,10.8,82.8,c_white,true); 
				graph_rect(x1,329.6,75.6,10.8,c_blue,true);  	
				graph_rect(xm1, 8.665, 25.2, 3.6, c_blue,true);       
				graph_rect(xm2, 12.265, 3.6, 27.585, c_blue,true);      
				graph_rect(xm2, 43.45, 3.6, 27.585, c_white,true);       
				graph_rect(xm1, 71.035, 25.2, 3.6, c_blue,true);      
				graph_rect(xm3, 43.45, 3.6, 27.585, c_blue,true);     
				graph_rect(xm3, 12.265 ,3.6 ,27.585 ,c_white,true);    
				graph_rect(xm1, 39.85, 25.2, 3.6, c_blue,true);      
			}
			if(array_de_algarismos[i]==3) {
				graph_rect(x1,236,75.6,10.8,c_blue,true);      
				graph_rect(x2,246.8,10.8,82.8,c_blue,true);     
				graph_rect(x2,340.4,10.8,82.8,c_blue,true);     
				graph_rect(x1,423.2,75.6,10.8,c_blue,true);    
				graph_rect(x3,340.4,10.8,82.8,c_white,true);   
				graph_rect(x3,246.8,10.8,82.8,c_white,true);   
				graph_rect(x1,329.6,75.6,10.8,c_blue,true);     
				graph_rect(xm1, 8.665, 25.2, 3.6, c_blue,true);         
				graph_rect(xm2, 12.265, 3.6, 27.585, c_blue,true);      
				graph_rect(xm2, 43.45, 3.6, 27.585, c_blue,true);       
				graph_rect(xm1, 71.035, 25.2, 3.6, c_blue,true);      
				graph_rect(xm3, 43.45, 3.6, 27.585, c_white,true);       
				graph_rect(xm3, 12.265 ,3.6 ,27.585 ,c_white,true);      
				graph_rect(xm1, 39.85, 25.2, 3.6, c_blue,true);        
			}
			if(array_de_algarismos[i]==4) {
				graph_rect(x1,236,75.6,10.8,c_white,true);    
				graph_rect(x2,246.8,10.8,82.8,c_blue,true);   
				graph_rect(x2,340.4,10.8,82.8,c_blue,true);  
				graph_rect(x1,423.2,75.6,10.8,c_white,true); 
				graph_rect(x3,340.4,10.8,82.8,c_white,true);  
				graph_rect(x3,246.8,10.8,82.8,c_blue,true);   
				graph_rect(x1,329.6,75.6,10.8,c_blue,true);  
				graph_rect(xm1, 8.665, 25.2, 3.6, c_white,true);         
				graph_rect(xm2, 12.265, 3.6, 27.585, c_blue,true);     
				graph_rect(xm2, 43.45, 3.6, 27.585, c_blue,true);      
				graph_rect(xm1, 71.035, 25.2, 3.6, c_white,true);    
				graph_rect(xm3, 43.45, 3.6, 27.585, c_white,true);      
				graph_rect(xm3, 12.265 ,3.6 ,27.585 ,c_blue,true);     
				graph_rect(xm1, 39.85, 25.2, 3.6, c_blue,true);       
			}
			if(array_de_algarismos[i]==5)  
			{
				graph_rect(x1,236,75.6,10.8,c_blue,true);        
				graph_rect(x2,246.8,10.8,82.8,c_white,true);     
				graph_rect(x2,340.4,10.8,82.8,c_blue,true);      
				graph_rect(x1,423.2,75.6,10.8,c_blue,true);      
				graph_rect(x3,340.4,10.8,82.8,c_white,true);     
				graph_rect(x3,246.8,10.8,82.8,c_blue,true);      
				graph_rect(x1,329.6,75.6,10.8,c_blue,true);      
				graph_rect(xm1, 8.665, 25.2, 3.6, c_blue,true);         
				graph_rect(xm2, 12.265, 3.6, 27.585, c_white,true);        
				graph_rect(xm2, 43.45, 3.6, 27.585, c_blue,true);         
				graph_rect(xm1, 71.035, 25.2, 3.6, c_blue,true);        
				graph_rect(xm3, 43.45, 3.6, 27.585, c_white,true);       
				graph_rect(xm3, 12.265 ,3.6 ,27.585 ,c_blue,true);      
				graph_rect(xm1, 39.85, 25.2, 3.6, c_blue,true);       
			}
			if(array_de_algarismos[i]==6) {
				graph_rect(x1,236,75.6,10.8,c_blue,true);         
				graph_rect(x2,246.8,10.8,82.8,c_white,true);      
				graph_rect(x2,340.4,10.8,82.8,c_blue,true);       
				graph_rect(x1,423.2,75.6,10.8,c_blue,true);       
				graph_rect(x3,340.4,10.8,82.8,c_blue,true);       
				graph_rect(x3,246.8,10.8,82.8,c_blue,true);       
				graph_rect(x1,329.6,75.6,10.8,c_blue,true);       
				graph_rect(xm1, 8.665, 25.2, 3.6, c_blue,true);         
				graph_rect(xm2, 12.265, 3.6, 27.585, c_white,true);        
				graph_rect(xm2, 43.45, 3.6, 27.585, c_blue,true);        
				graph_rect(xm1, 71.035, 25.2, 3.6, c_blue,true);        
				graph_rect(xm3, 43.45, 3.6, 27.585, c_blue,true);       
				graph_rect(xm3, 12.265 ,3.6 ,27.585 ,c_blue,true);/     
				graph_rect(xm1, 39.85, 25.2, 3.6, c_blue,true);       
			}
			if(array_de_algarismos[i]==7) {
				graph_rect(x1,236,75.6,10.8,c_blue,true);       
				graph_rect(x2,246.8,10.8,82.8,c_blue,true);     
				graph_rect(x2,340.4,10.8,82.8,c_blue,true);     
				graph_rect(x1,423.2,75.6,10.8,c_white,true);    
				graph_rect(x3,340.4,10.8,82.8,c_white,true);    
				graph_rect(x3,246.8,10.8,82.8,c_white,true);    
				graph_rect(x1,329.6,75.6,10.8,c_white,true);    
				graph_rect(xm1, 8.665, 25.2, 3.6, c_blue,true);         
				graph_rect(xm2, 12.265, 3.6, 27.585, c_blue,true);        
				graph_rect(xm2, 43.45, 3.6, 27.585, c_blue,true);         
				graph_rect(xm1, 71.035, 25.2, 3.6, c_white,true);        
				graph_rect(xm3, 43.45, 3.6, 27.585, c_white,true);       
				graph_rect(xm3, 12.265 ,3.6 ,27.585 ,c_white,true);     
				graph_rect(xm1, 39.85, 25.2, 3.6, c_white,true);        
			}
			if(array_de_algarismos[i]==8) {
				graph_rect(x1,236,75.6,10.8,c_blue,true);       
				graph_rect(x2,246.8,10.8,82.8,c_blue,true);     
				graph_rect(x2,340.4,10.8,82.8,c_blue,true);     
				graph_rect(x1,423.2,75.6,10.8,c_blue,true);    
				graph_rect(x3,340.4,10.8,82.8,c_blue,true);     
				graph_rect(x3,246.8,10.8,82.8,c_blue,true);     
				graph_rect(x1,329.6,75.6,10.8,c_blue,true);     
				graph_rect(xm1, 8.665, 25.2, 3.6, c_blue,true);         
				graph_rect(xm2, 12.265, 3.6, 27.585, c_blue,true);      
				graph_rect(xm2, 43.45, 3.6, 27.585, c_blue,true);        
				graph_rect(xm1, 71.035, 25.2, 3.6, c_blue,true);        
				graph_rect(xm3, 43.45, 3.6, 27.585, c_blue,true);       
				graph_rect(xm3, 12.265 ,3.6 ,27.585 ,c_blue,true);      
				graph_rect(xm1, 39.85, 25.2, 3.6, c_blue,true);        
			}
			if(array_de_algarismos[i]==9)  {
				graph_rect(x1,236,75.6,10.8,c_blue,true);       
				graph_rect(x2,246.8,10.8,82.8,c_blue,true);     
				graph_rect(x2,340.4,10.8,82.8,c_blue,true);     
				graph_rect(x1,423.2,75.6,10.8,c_blue,true);     
				graph_rect(x3,340.4,10.8,82.8,c_white,true);    
				graph_rect(x3,246.8,10.8,82.8,c_blue,true);     
				graph_rect(x1,329.6,75.6,10.8,c_blue,true);     
				graph_rect(xm1, 8.665, 25.2, 3.6, c_blue,true);         
				graph_rect(xm2, 12.265, 3.6, 27.585, c_blue,true);       
				graph_rect(xm2, 43.45, 3.6, 27.585, c_blue,true);        
				graph_rect(xm1, 71.035, 25.2, 3.6, c_blue,true);        
				graph_rect(xm3, 43.45, 3.6, 27.585, c_white,true);      
				graph_rect(xm3, 12.265 ,3.6 ,27.585 ,c_blue,true);    
				graph_rect(xm1, 39.85, 25.2, 3.6, c_blue,true);        
			}
		}
graph_start();
} else {
	printf("ERRO-Valor inserido não se encontra dentro do intervalo pedido");
}
return 0;
}