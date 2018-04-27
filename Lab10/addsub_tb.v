module addsub_tb;

reg[31:0] a, b;
wire[31:0] result;
reg control;

initial
begin
$dumpfile("addsub_tb.vcd");
$dumpvars(0, addsub_tb);

#1control = 1;
a = 4;
b = 7;

#1control = 0;
a = 5;
b = 8;

#1control = 1;
a = 25;
b = 37;

#1control = 0;
a = 8;
b = 5;
   
#2 $finish;
   
end

addsub as1(.result(result), .a(a), .b(b), .control(control));

initial
  $monitor("a = %d : b = %d : control = %d : result = %d", a, b, control, result);


endmodule
