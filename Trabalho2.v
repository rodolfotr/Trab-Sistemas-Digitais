module values(input CLOCK_50, input [0:0]KEY, output [0:0]LEDG);
   
   reg [25:0] counter;
   reg state=0;
   
   assign LEDG = state;
   
   always @(posedge CLOCK_50) begin
   	if(KEY[0] == 1) begin
   	counter = 0;
   	state = 0;
   	end else begin
      		if(cont == 50000000) begin
	 cont = 0;
	 state = ~state;
	end else begin
		cont <= cont + 1;
      	end
      	end
   end
   
endmodule
