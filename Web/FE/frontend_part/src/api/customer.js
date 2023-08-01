import { publicApi, authorizedApi } from "./axiosInstances";

// 사용자 등록
const registercustomer = async (customerDto) => {
  try {
    const response = await publicApi.post("/customer/register", customerDto);
    return response;
  } catch (error) {
    throw new Error(`사용자 등록 에러: ${error.message}`);
  }
};

// 사용자 로그인
const login = async (customerLoginDto) => {
  try {
    const response = await publicApi.post("/customer/login", customerLoginDto);
    return response;
  } catch (error) {
    throw new Error(`사용자 로그인 에러: ${error.message}`);
  }
};

// Access Token 갱신
const refreshToken = async (refreshTokenDTO) => {
  try {
    const response = await authorizedApi.post("/customer/refresh", refreshTokenDTO);
    return response;
  } catch (error) {
    throw new Error(`Access Token 갱신 에러: ${error.message}`);
  }
};
