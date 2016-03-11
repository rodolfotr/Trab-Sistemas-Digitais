module TOP(input CLOCK_50, input reset, output [1:0]LED);
   
   reg [32:0] cont;
   reg LedOn=0;
   
   assign LED[0] = LedOn;
   assign LED[1] = ~LedOn;
   initial begin
   cont[25:0] <= 0;
   end
   always @(posedge CLOCK_50) begin
   	if(reset ==1) begin
   	cont = 0;
   	LedOn = 0;
   	end
      if(cont == 5000) begin
	 LedOn = ~LedOn;
	 cont = 0;
      end
      else begin
	 cont <= cont+1;
      end
   end
   
endmodule
   
module test;
   
   reg reset, clk;
   wire [1:0]Led;
   
   
   TOP A(cont, reset, LED);
   
   always #1 clk = ~clk;
   
   initial begin
      $dumpvars(0, A);
      #0;
      reset <= 1;
      #1
      reset <= 0;
      clk <= 0;
      #600000;
      $finish;   
   end
endmodule
