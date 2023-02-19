import 'package:flutter/material.dart';

class CalcProvider extends ChangeNotifier {
  List<String> inputDatas = [];
  List<String> resultDatas = [];
  String inputData = '';
  double? result;
  final TextEditingController _calcController = TextEditingController();

  TextEditingController get calcController => _calcController;

  void onPressedButton(final String buttonText) {
    switch (buttonText) {
      case "=":
        showResult(buttonText);
        break;
      case "AC":
        resetValue(buttonText);
        break;
      case "C":
        clearValue(buttonText);
        break;
      default:
        inputNumbers(buttonText);
    }
    notifyListeners();
  }

  void showResult(final String buttonText) {
    inputData = _calcController.text;
    /* int firstnumber = int.parse(inputData.split(RegExp(r'[+,-,*,/]'))[0]);

    String op = inputData.split(RegExp(r'[0-9]'))[1];
    int secondnumber = int.parse(inputData.split(RegExp(r'[+,-,*,/]'))[1]);
      List<String> elements = inputData.split(new RegExp(r"([+,-,*,/])"));
    double firstnumber = double.parse(elements[0].trim());
    double secondnumber = double.parse(elements[2].trim());
    String op = elements[1].trim();
*/
    double firstnumber = double.parse(inputData.split(RegExp(r'[+,-,*,/]'))[0]);

    double secondnumber =
        double.parse(inputData.split(RegExp(r'[+,-,*,/]'))[1]);
    String op = inputData.split(RegExp(r'[0-9]'))[1];

    switch (op) {
      case '+':
        result = firstnumber + secondnumber;
        break;
      case '-':
        result = firstnumber - secondnumber;
        break;
      case '*':
        result = firstnumber * secondnumber;
        break;
      case '/':
        result = firstnumber / secondnumber;
        break;
      //   case '%' :
      // result = (firstnumber*secondnumber)/100;
      //break;

      default:
        result = 0;
    }
    inputDatas.add(_calcController.text);
    resultDatas.add(result.toString());
  }

  void resetValue(final String buttonText) {
    _calcController.text = "";
    result = 0;
  }

  void clearValue(final String buttonText) {
    if (_calcController.text.isNotEmpty) {
      _calcController.text =
          _calcController.text.substring(0, _calcController.text.length - 1);
    }
  }

  void inputNumbers(final String buttonText) {
    _calcController.text += buttonText;
  }

  void resetHistoryDatas() {
    inputDatas = [];
    resultDatas = [];
  }
}
