module TOP(input CLOCK_50, output [1:0]LED);
   
   reg [32:0] cont;
   reg LedOn=0;
   
   assign LED[0] = LedOn;
   assign LED[1] = ~LedOn;
   initial begin
   cont[32:0] <= 0;
   end
   always @(posedge CLOCK_50) begin		
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
   
   reg clk;
   wire [1:0]Led;
   
   
   TOP A(cont,
		Led);
   
   always #1 clk = ~clk;
   
   initial begin
      $dumpvars(0, A);
      #0;
      reset <= 1;
      #1
      reset <= 0;
      clk <= 0;
      #400000000;
      $finish;   
   end
endmodule
