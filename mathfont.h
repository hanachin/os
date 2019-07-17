int font_c33(float x,float y){return (((0.03125-pow(x, 2))-pow((y+0.75), 2))*(((4.0*pow(x, 2))+pow((y-0.3333333333333333), 6))-0.125))>0;}
int font_c34(float x,float y){return ((1.0-((((16.0*pow(x, 4))+(0.015625/pow(x, 2)))-0.25)*pow(16, (1.0-y))))-pow(((4.0*y)-3.0), 2))>0;}
int font_c35(float x,float y){return ((0.25-pow(((pow(((3.0*x)-(y/2.0)), 2)+(4.0*pow(y, 2)))/5.0), 8))-pow((cos(((6.0*x)-y))*cos((4.0*y))), 2))>0;}
int font_c36(float x,float y){float r = sqrt(x*x+y*y);float th = atan2(y,x);return (0.25-((((32.0*pow((r*cos((((th+(8.0*r))-(4.0*pow(r, 2)))-3.5))), 2))+pow((r*sin((((th+(8.0*r))-(4.0*pow(r, 2)))-3.5))), 4))-0.5)*(((32.0*pow(x, 2))+((4.0*pow(y, 2))*pow((pow(y, 2)-0.5), 4)))-0.03125)))>0;}
int font_c37(float x,float y){return (((pow(((pow(((6.0*x)+2.0), 2)+pow(((6.0*y)-3.0), 2))-2.0), 2)-2.0)*(pow(((pow(((6.0*x)-2.0), 2)+pow(((6.0*y)+3.0), 2))-2.0), 2)-2.0))*((3.0-pow(((12.0*x)-(8.0*y)), 2))-pow((y+((3.0*x)/4.0)), 8)))>0;}
int font_c38(float x,float y){return (((((((1.0-(13.0/(16.0+(100.0*pow(y, 2)))))-(0.0125/(pow((x+0.0625), 2)+pow((y-0.4375), 2))))-(1.0/((30.0*pow((x-(((5.0*y)+1.0)/15.0)), 2))+(50.0*pow((y+0.4), 2)))))-((3.0*pow((x+((1.0-y)/8.0)), 2))*exp((y/2.0))))-(2.0*pow(y, 4)))+(2.0/((1.0+(10.0*pow(((x-y)-1.0), 4)))+(80.0*pow((x+y), 2)))))+(2.0/((1.0+(80.0*pow(((x-y)-0.75), 2)))+(10.0*pow(((y+x)-0.75), 4)))))>0;}
int font_c39(float x,float y){return ((1.0-((24.0*pow(x, 2))*pow(8, (1.0-y))))-pow(((4.0*y)-3.0), 2))>0;}
int font_c40(float x,float y){return ((1.0-pow((((8.0*x)-(4.0*pow(y, 2)))+2.0), 2))-pow(y, 16))>0;}
int font_c41(float x,float y){return ((1.0-pow((((8.0*x)+(4.0*pow(y, 2)))-2.0), 2))-pow(y, 16))>0;}
int font_c42(float x,float y){float r = sqrt(x*x+y*y);float th = atan2(y,x);return ((3.0-cos((6.0*th)))-(6.0*r))>0;}
int font_c43(float x,float y){float r = sqrt(x*x+y*y);float th = atan2(y,x);return (((2.0+cos((4.0*th)))+(cos((8.0*th))/6.0))-(5.0*r))>0;}
int font_c44(float x,float y){return (((0.03125-pow(x, 2))-pow((y+0.75), 2))-(((128.0*x)*y)/((1.0+pow((128.0*x), 2))+pow(((64.0*y)+72.0), 2))))>0;}
int font_c45(float x,float y){return ((1.0-(6.0*pow(x, 4)))-(40.0*pow(y, 2)))>0;}
int font_c46(float x,float y){return ((0.03125-pow(x, 2))-pow((y+0.75), 2))>0;}
int font_c47(float x,float y){return ((8.0-(64.0*pow((y-(2.0*x)), 2)))-pow((y+(x/2.0)), 8))>0;}
int font_c58(float x,float y){return ((-((0.03125-pow(x, 2))-pow((y+0.75), 2)))*((0.03125-pow(x, 2))-pow((y-0.5), 2)))>0;}
int font_c59(float x,float y){return ((-(((0.03125-pow(x, 2))-pow((y+0.75), 2))-(((128.0*x)*y)/((1.0+pow((128.0*x), 2))+pow(((64.0*y)+72.0), 2)))))*((0.03125-pow(x, 2))-pow((y-0.5), 2)))>0;}
int font_c60(float x,float y){return ((1.0-pow((((4.0*x)+3.0)-((3.0*sqrt((1.0+(32.0*pow(y, 2)))))/2.0)), 2))-(64.0*pow(y, 8)))>0;}
int font_c61(float x,float y){return (((1.0-(3.0*pow(x, 4)))-(10.0*pow(y, 4)))-(0.05/pow(y, 2)))>0;}
int font_c62(float x,float y){return ((1.0-pow((((4.0*x)-3.0)+((3.0*sqrt((1.0+(32.0*pow(y, 2)))))/2.0)), 2))-(64.0*pow(y, 8)))>0;}
int font_c63(float x,float y){return ((((20.0-(1.0/pow(((2.0*pow(((x-(y/2.0))+0.3333333333333333), 2))+pow(y, 2)), 2)))+(1.0/pow((pow(x, 2)+pow((y+0.75), 2)), 2)))+(0.125/pow(((4.0*pow(x, 2))+pow((y+0.25), 2)), 2)))-pow((((24.0*pow(x, 2))+(48.0*pow((y-0.3333333333333333), 2)))-6.0), 2))>0;}
int font_c64(float x,float y){return ((((2.0/(1.0+(2.0*pow((((8.0*pow(x, 2))+(8.0*pow(y, 4)))-2.0), 4))))+(1.0/(1.0+pow((((12.0*pow((x-0.2), 2))+pow(((2.0*y)+0.25), 4))-1.0), 4))))+(4.0/(pow(((4.0*x)-1.0), 4)+pow(((24.0*y)+16.0), 2))))-1.0)>0;}
int font_c91(float x,float y){return (((1.0-(128.0/((1.0+(16.0*pow(((2.0*x)-1.0), 8)))+pow((2.0*y), 16))))-(32.0*pow(x, 4)))-(2.0*pow(y, 8)))>0;}
int font_c92(float x,float y){return ((8.0-(64.0*pow((y+(2.0*x)), 2)))-pow((y-(x/2.0)), 8))>0;}
int font_c93(float x,float y){return (((1.0-(128.0/((1.0+(16.0*pow(((2.0*x)+1.0), 8)))+pow((2.0*y), 16))))-(32.0*pow(x, 4)))-(2.0*pow(y, 8)))>0;}
int font_c94(float x,float y){return ((1.0-pow((((6.0*y)-5.0)+sqrt((1.0+(32.0*pow(x, 2))))), 2))-(64.0*pow(x, 8)))>0;}
int font_c95(float x,float y){return ((1.0-(6.0*pow(x, 4)))-(40.0*pow((y+0.8), 2)))>0;}
int font_c96(float x,float y){return ((0.25-pow((((2.0*x)-y)+0.8333333333333334), 4))-(4.0*pow((((2.0*y)-1.6666666666666667)+x), 2)))>0;}
int font_c123(float x,float y){return ((1.0-pow(((((8.0*x)+(2.0*pow(y, 2)))-(3.0*pow(y, 4)))+(3.0/(2.0+(64.0*pow(y, 2))))), 2))-pow(y, 16))>0;}
int font_c124(float x,float y){return ((4.0-(256.0*pow(x, 2)))-pow(y, 16))>0;}
int font_c125(float x,float y){return ((1.0-pow(((((8.0*x)-(2.0*pow(y, 2)))+(3.0*pow(y, 4)))-(3.0/(2.0+(64.0*pow(y, 2))))), 2))-pow(y, 16))>0;}
int font_c126(float x,float y){return ((0.03125-pow(x, 8))-pow((y+(sin((6.0*x))/8.0)), 2))>0;}
int font_c0(float x,float y){return (1.0-pow((((8.0*pow((x-(y/8.0)), 2))+(4.0*pow(y, 2)))-2.6666666666666665), 2))>0;}
int font_c1(float x,float y){return ((1.0-(32.0*pow((x-(y/8.0)), 2)))-(2.0*pow(y, 8)))>0;}
int font_c2(float x,float y){return (((0.03125-exp((((-4.0*x)-(2.0*y))-4.0)))+(1.0/((2.0*pow((x-0.0), 8))+(4.0*pow(((4.0*y)+3.0), 2)))))-pow(((pow((x+((1.0-y)/2.0)), 2)+pow(y, 2))-0.5), 2))>0;}
int font_c3(float x,float y){return ((((((1.0-((8.0*pow(x, 2))/(1.0+(64.0*pow(y, 2)))))-(1.0/((20.0*pow((x+((1.0-y)/8.0)), 2))+(32.0*pow((y-0.4), 2)))))-(1.0/((20.0*pow((x+((1.0-y)/8.0)), 2))+(20.0*pow((y+0.4), 2)))))-((exp(((y/2.0)-(4.0*x)))-pow(y, 2))/8.0))-(2.0*pow((x+((1.0-y)/8.0)), 2)))-pow(y, 4))>0;}
int font_c4(float x,float y){return ((1.0-(1.0/(pow((x-0.125), 2)+pow((((4.0*y)-3.0)/2.0), 2))))-(((((((12.0*pow((x-(y/3.0)), 2))+(2.0*y))-0.6666666666666666)+pow(((2.0*y)-0.6666666666666666), 4))-0.5)*(((((12.0*pow((x-(y/3.0)), 2))+(3.0*y))-1.0)+(16.0*pow((y-0.3333333333333333), 4)))-2.0))*((pow((((8.0*x)-3.0)-(y/2.0)), 2)+pow(((2.0*y)+1.0), 4))-1.0)))>0;}
int font_c5(float x,float y){return (((1.0+(1.0/(pow(((2.0*x)-1.0), 4)+pow(((5.0*y)-4.0), 2))))-pow(((x/4.0)+y), 4))-pow(((((8.0*x)-(2.0*y))+2.0)+((4.0*sin((((x+(4.0*y))*5.0)/6.0)))/(1.0+exp(((4.0*x)+(16.0*y)))))), 2))>0;}
int font_c6(float x,float y){return (((4.0/(1.0+(32.0*pow(((pow(x, 2)+pow((y+0.5), 2))-0.2), 2))))+(4.0/((1.0+(32.0*pow(((x+((1.0-y)/3.0))-(pow(y, 2)/2.0)), 2)))+(4.0*pow((y-0.5), 4)))))-3.0)>0;}
int font_c7(float x,float y){return ((2.0-pow((((((4.0*x)+(4.0*y))-1.0)+((8.0*(x-y))/3.0))-(3.0*cos(((((12.0*x)-(12.0*y))+3.0)/5.0)))), 2))-pow(((x-y)+0.25), 4))>0;}
int font_c8(float x,float y){return (((((1.0-(1.0/(4.0+(64.0*pow(y, 2)))))-(1.0/((20.0*pow((x-(y/8.0)), 2))+(32.0*pow((y-0.4), 2)))))-(1.0/((16.0*pow((x-(y/8.0)), 2))+(24.0*pow((y+0.4), 2)))))-((2.0*pow((x-(y/8.0)), 2))*exp((y/4.0))))-pow(y, 4))>0;}
int font_c9(float x,float y){return (((4.0/(1.0+(32.0*pow(((pow(x, 2)+pow((y-0.5), 2))-0.2), 2))))+(4.0/((1.0+(32.0*pow(((x-((1.0+y)/3.0))+(pow(y, 2)/2.0)), 2)))+(4.0*pow((y+0.5), 4)))))-3.0)>0;}
int font_a(float x,float y){return (((0.5+(32.0/(1.0+(512.0*(pow(x, 4)+pow((y+0.25), 2))))))-pow(x, 6))-pow((((1.5-(2.0*y))-(8.0*pow(x, 2)))+(5.0*pow(x, 4))), 2))>0;}
int font_b(float x,float y){return (((2.0-(1.0/(pow(cos((4.0*y)), 2)+(16.0*pow(x, 4)))))-(8.0*pow((x-(((sqrt((1.0-cos((7.0*y))))-1.0)/5.0)/(1.0+exp((-8.0*x))))), 4)))-pow(y, 4))>0;}
int font_c(float x,float y){float th = atan2(y,x);return ((0.5-pow(((1.0+cos(th))/2.0), 16))-pow((((4.0*pow(x, 2))+(3.0*pow(y, 2)))-2.0), 2))>0;}
int font_d(float x,float y){return (0.08333333333333333-pow(((pow(y, 2)+pow(((((3.0*x)/2.0)+(pow(y, 2)/2.0))+(pow(y, 4)/16.0)), 2))-0.75), 2))>0;}
int font_e(float x,float y){return (((2.0-(6.0*pow(x, 4)))-pow(y, 4))-((4.0*(1.0-pow(cos((4.0*y)), 4)))/(1.0+exp(((-16.0*x)-8.0)))))>0;}
int font_f(float x,float y){return ((((2.0-(8.0*pow(x, 4)))-(2.0*pow(y, 4)))+pow(y, 2))-(((2.0*(1.0-pow(cos((pow(y, 2)+(3.0*y))), 6)))*(2.0-y))/(1.0+exp(((-16.0*x)-6.0)))))>0;}
int font_g(float x,float y){float th = atan2(y,x);return (((0.5-pow(((1.0+cos(th))/2.0), 16))+(2.0/((1.0+(4.0*pow(((4.0*x)-1.0), 8)))+(2.0*pow(((8.0*y)+2.0), 4)))))-pow(((pow(((2.0*x)+(1.0/((4.0+(4.0*pow(((2.0*x)-1.0), 4)))+pow(((4.0*y)+1.0), 4)))), 2)+(3.0*pow(y, 2)))-2.0), 2))>0;}
int font_h(float x,float y){return ((-5.0*(((16.0*pow(x, 8))+pow(y, 8))-1.0))-(9.0/(pow(((5.0*x)/2.0), 16)+(2.0*pow((pow(y, 2)-1.0), 4)))))>0;}
int font_i(float x,float y){return ((2.0-pow((8.0*x), 4))-pow(y, 8))>0;}
int font_j(float x,float y){return ((0.16666666666666666-exp(((8.0*y)-(10.0/(1.0+exp((-16.0*x)))))))-pow((((3.0*pow(x, 2))+(6.0*pow(((y/2.0)-0.25), 4)))-1.0), 2))>0;}
int font_k(float x,float y){return ((0.125-(64.0*pow(x, 8)))-((pow(((x+0.125)-sqrt((0.015625+pow(y, 2)))), 2)-0.03125)*((pow(((8.0*x)+3.0), 2)+pow(y, 8))-1.0)))>0;}
int font_l(float x,float y){return (((1.0-(16.0*pow(x, 8)))-pow(y, 8))-(64.0/(pow(((2.0*x)-1.0), 8)+pow((y-1.0), 8))))>0;}
int font_m(float x,float y){return (((1.0-(12.0/((4.0+(4.0*pow((2.0*x), 8)))+pow(((y-2.0)+((4.0+(6.0*pow(x, 4)))/(1.0+(2.0*pow(x, 2))))), 8))))-(8.0*pow(x, 8)))-pow(((y+((4.0+(6.0*pow(x, 4)))/(1.0+(2.0*pow(x, 2)))))-2.75), 8))>0;}
int font_n(float x,float y){return (((((1.0/(4.0+(64.0*pow(((2.0*x)+y), 2))))-(64.0*pow(x, 8)))+(8.0*pow(x, 4)))-pow((y-(x/8.0)), 8))-0.125)>0;}
int font_o(float x,float y){return (0.25-pow((((3.0*pow(x, 2))+(2.0*pow(y, 4)))-1.0), 2))>0;}
int font_p(float x,float y){return (1.0-((pow((((8.0*pow(x, 2))+(2.0*pow(((2.0*y)-1.0), 2)))-2.0), 2)-1.0)*((pow(((8.0*x)+4.0), 4)+pow(y, 8))-1.0)))>0;}
int font_q(float x,float y){return ((0.25+(((2.0+(4.0*x))/(1.0+pow((((8.0*y)-(2.0*cos((3.0*x))))+5.0), 8)))/(1.0+exp(((-32.0*x)-10.0)))))-pow((((3.0*pow(x, 2))+(2.0*pow(y, 4)))-1.0), 2))>0;}
int font_r(float x,float y){return ((-(((atan(((3.0*pow(x, 2))+(3.0*pow((y-0.5), 2))))*atan((pow(((8.0*x)+4.0), 4)+pow(y, 8))))*atan((pow((((8.0*x)-1.0)+(2.0*y)), 4)+(4.0*pow((y+0.25), 4)))))-2.0))*(((8.0*pow(x, 2))+(2.0*pow(((2.0*y)-1.0), 2)))-1.0))>0;}
int font_s(float x,float y){return ((0.16666666666666666-pow(x, 4))-pow((pow((x-(y/2.0)), 3)+((2.0*(x+y))*(1.0-pow((y+(x/4.0)), 2)))), 2))>0;}
int font_t(float x,float y){return (1.0-((((4.0*pow(x, 8))+(3.0*pow(((4.0*y)-3.0), 2)))-1.0)*(((32.0*pow(x, 2))+(3.0*pow((y+0.25), 8)))-1.0)))>0;}
int font_u(float x,float y){return ((0.16666666666666666-exp(((16.0*y)-16.0)))-pow((((3.0*pow(x, 2))+(5.0*pow(((y/2.0)-0.25), 4)))-1.0), 2))>0;}
int font_v(float x,float y){return ((0.5-pow(x, 6))-pow(((((2.0*y)+1.5)-(8.0*pow(x, 2)))+(5.0*pow(x, 4))), 2))>0;}
int font_w(float x,float y){return ((1.0-pow(x, 8))-pow(((((3.0*y)-(2.0*cos((6.0*x))))-(3.0*pow(x, 2)))+(2.0*pow(x, 4))), 2))>0;}
int font_x(float x,float y){float r = sqrt(x*x+y*y);float th = atan2(y,x);return ((3.0*atan(((2.0+pow(tan(((2.0*th)-(sin((2.0*th))/4.0))), 2))/6.0)))-(4.0*r))>0;}
int font_y(float x,float y){float r = sqrt(x*x+y*y);float th = atan2(y,x);return ((3.0*atan(((2.0+pow(tan((((((3.0*th)/2.0)+0.7853981633974483)-(cos(th)/2.0))-(sin((2.0*th))/4.0))), 2))/8.0)))-(4.0*r))>0;}
int font_z(float x,float y){return (((((1.0/(4.0+(128.0*pow((x-y), 2))))-(2.0*pow(y, 8)))+((5.0*pow(y, 4))/4.0))-pow((x+(y/8.0)), 8))-0.125)>0;}
