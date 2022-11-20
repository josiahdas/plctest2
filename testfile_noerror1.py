##########
#copy this code into the lex_analyzer.py scanner  
###########

FUN join(elements, separator)
    VAR result = ""
    VAR len = LEN(elements)

    LOOP i = 0 TO len THEN
        VAR result = result + elements/i
        INCASE i != len - 1 THEN VAR result = result + separator
    END

    RETURN result
END