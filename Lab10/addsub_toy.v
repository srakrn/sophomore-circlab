module addsub(a,b,result,control);
	input[31:0] a,b;
	input control;
	output[31:0] result;
	reg[31:0] tmp;
	reg cin;
	wire cout;

	assign result = control ? a + b : a - b;

endmodule
