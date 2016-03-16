module Led(input CLOCK_50, output [1:0]LEDR);

    reg [32:0] counter;
    reg state = 0;
    
    assign LEDR[0] = state;
    assign LEDR[1] = ~state;
    
    always @(posedge CLOCK_50) begin
        if (counter == 50000000) begin
            state = ~state;
            counter = 0;
        end else begin
            counter <= counter + 1;
        end
    end

endmodule
