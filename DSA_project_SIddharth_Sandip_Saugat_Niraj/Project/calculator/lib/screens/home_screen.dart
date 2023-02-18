import 'package:calci/screens/history_list.dart';
import 'package:calci/widgets/calc_input.dart';
import 'package:calci/widgets/calc_keyboard_layout.dart';
import 'package:flutter/material.dart';

class HomeScreen extends StatefulWidget {
  const HomeScreen({super.key});

  @override
  State<HomeScreen> createState() => _HomeScreenState();
}

class _HomeScreenState extends State<HomeScreen> {
  final TextEditingController _calcController = TextEditingController();

  @override
  Widget build(BuildContext context) {
    return WillPopScope(
      onWillPop: () async {
        return Future.value(true);
      },
      child: Scaffold(
        backgroundColor: Colors.grey[300],
        body: Container(
          decoration: BoxDecoration(
            gradient: LinearGradient(
                colors: [Colors.grey.shade300, Colors.white],
                begin: Alignment.topCenter,
                end: Alignment.bottomCenter),
          ),
          child: Padding(
            padding: const EdgeInsets.symmetric(horizontal: 8.0),
            child: Column(
              mainAxisAlignment: MainAxisAlignment.end,
              crossAxisAlignment: CrossAxisAlignment.end,
              children: [
                SafeArea(
                  child: IconButton(
                    onPressed: () {
                      Navigator.push(
                        context,
                        MaterialPageRoute(
                          builder: (context) {
                            return const HistoryList();
                          },
                        ),
                      );
                    },
                    icon: const Icon(Icons.history),
                  ),
                ),
                Expanded(
                  child: CalcInput(
                    controller: _calcController,
                  ),
                ),
                Expanded(
                  flex: 3,
                  child: Container(
                    child: CalcKeyboardLayout(),
                  ),
                )
              ],
            ),
          ),
        ),
      ),
    );
  }
}
