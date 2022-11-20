
##########
#copy this code into the lex_analyzer.py scanner  
###########

FUN map(elements, func)
    VAR new_elements = []

    LOOP i = 0 TO LEN(elements) THEN
        APPEND(new_elements, func(elements/i))
    END

    RETURN new_elements
END
