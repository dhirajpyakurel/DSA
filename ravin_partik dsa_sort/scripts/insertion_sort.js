function Insertion()
{
    c_delay=0;

    for(var j=0;j<array_size;j++)
    {
        div_update(divs[j],div_sizes[j],"#ffc42a");

        var key= div_sizes[j];
        var i=j-1;
        while(i>=0 && div_sizes[i]>key)
        {
            div_update(divs[i],div_sizes[i],"red");
            div_update(divs[i+1],div_sizes[i+1],"red");

            div_sizes[i+1]=div_sizes[i];

            div_update(divs[i],div_sizes[i],"red");
            div_update(divs[i+1],div_sizes[i+1],"red");
    
            div_update(divs[i],div_sizes[i],"#234e70");
            if(i==(j-1))
            {
                div_update(divs[i+1],div_sizes[i+1],"#ffc42a");
            }
            else
            {
                div_update(divs[i+1],div_sizes[i+1],"#234e70");
            }
            i-=1;
        }
        div_sizes[i+1]=key;

        for(var t=0;t<j;t++)
        {
            div_update(divs[t],div_sizes[t],"#6ACFC7");
        }
    }
    div_update(divs[j-1],div_sizes[j-1],"#6ACFC7");

    enable_buttons();
}