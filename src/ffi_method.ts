import { load, DataType, open, close } from "ffi-rs";
import { libName } from "./utils";

open({
  library: "math",
  path: libName("math"),
});

export async function callAddFunction(a: number, b: number): Promise<number> {
  const result = await load({
    library: "math",
    funcName: "add",
    retType: DataType.I32,
    paramsType: [DataType.I32, DataType.I32],
    paramsValue: [a, b],
  });

  return result as number;
}
