import lex_analyzer_code

while True:
    text = input('input code for lex  > ')
    result, error = lex_analyzer_code.run('<stdin>', text)

    if error: print(error.as_string())
    else: print(result)